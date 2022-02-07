#include <iostream>
#include <vector>
#include <windows.h>


using namespace std;

void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

class AActor
{
public:
	AActor()
	{
	}
	virtual ~AActor()
	{
	}

	virtual void Tick()
	{
		cout << "Actor Tick();" << endl;
	}

};

class ACubeActor : public AActor
{
public:
	ACubeActor()
	{
	}
	virtual ~ACubeActor()
	{
	}

	virtual void Tick() override
	{
		cout << "Cube Tick();" << endl;
	}
};

class AFloor : public ACubeActor
{
public:
	AFloor()
	{
	}
	virtual ~AFloor()
	{
	}

	virtual void Tick() override
	{
		cout << " ";
	}
};

class AWall : public ACubeActor
{
public:
	AWall()
	{
	}
	virtual ~AWall()
	{
	}

	virtual void Tick() override
	{
		cout << "*";
	}
};

class APlayer : public AActor
{
public:
	APlayer()
	{
	}
	virtual ~APlayer()
	{
	}

	virtual void Tick() override
	{
		cout << "P";
	}
};

class AGoal : public AActor
{
public:
	AGoal()
	{
	}
	virtual ~AGoal()
	{
	}

	virtual void Tick() override
	{
		cout << "G";
	}
};


class MyEngine
{
public:
	void Tick() {}
	void Input() {}
	void Render() {}

	vector<class Actor*> ActorList;
};

int main()
{
	int Map[10][10] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 9, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};


	AActor* Floor = new AFloor();
	AActor* Wall = new AWall();
	AActor* Player = new APlayer();
	AActor* Goal = new AGoal();

	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 10; ++X)
		{
			if (X == 1 && Y == 1)
			{
				Player->Tick();
			}

			else if (Map[Y][X] == 0)
			{
				Floor->Tick();
			}

			else if (Map[Y][X] == 1)
			{
				Wall->Tick();
			}

			else if (Map[Y][X] == 9)
			{
				Goal->Tick();
			}
		}
		cout << endl;
	}



	//delete object;
	//object = nullptr;

	return 0;
}

