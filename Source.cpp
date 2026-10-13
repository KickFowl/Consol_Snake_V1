#include <iostream>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>
#include <cmath>


using namespace std;

const int GAMEWIDTH = 40;
const int GAMEHEIGHT = 20;
const int ARREYSIZE = GAMEWIDTH * GAMEHEIGHT;

int x = GAMEWIDTH / 2;
int y = GAMEHEIGHT / 2;

int appleX;
int appleY;

int direction = 3;

int position = x + (GAMEWIDTH * y);

int applePosition = appleX + (GAMEWIDTH * appleY);

int tailLength = 4;

bool hasMoved = true;

bool touchingItself = false;

bool playing = true;

char restarts;

char gameFeild[ARREYSIZE] = {
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
};

int posData[ARREYSIZE];

void spawnApple(int count);

void restart() {
	x = GAMEWIDTH / 2;
	y = GAMEHEIGHT / 2;

	appleX = GAMEWIDTH / 2;
	appleY = GAMEHEIGHT / 2;

	direction = 3;

	position = x + (GAMEWIDTH * y);

	applePosition = appleX + (GAMEWIDTH * appleY);

	tailLength = 4;

	hasMoved = true;

	touchingItself = false;

	playing = true;

	restarts = ' ';

	for (int i = 0; i < ARREYSIZE; i++)
	{
		gameFeild[i] = ' ';
	}

	spawnApple(40);

}

void printPlayfeild()
{
	int arreyPlace = 0;

	for (int i = 0; i < GAMEWIDTH + 2; i++) {
		cout << '0';
	}

	cout << endl;

	for (int h = 0; h < GAMEHEIGHT; h++)
	{

		cout << '0';

		for (int w = 0; w < GAMEWIDTH; w++)
		{
			cout << gameFeild[arreyPlace];
			arreyPlace++;
		}
		cout << '0' << endl;
	}

	for (int i = 0; i < GAMEWIDTH + 2; i++) {
		cout << '0';
	}
}

void spawnApple(int count)
{
	for(int i = 0; i < count; i++)
	{
		int randX = rand() % GAMEWIDTH;
		int randY = rand() % GAMEHEIGHT;

		appleX = randX;
		appleY = randY;

		applePosition = appleX + (GAMEWIDTH * appleY);

		if (gameFeild[applePosition] == 'X')
		{
			tailLength++;
			spawnApple(1);
		}

		gameFeild[applePosition] = 'A';
	}
}

void snakeTouching()
{
	int tempPosition = x + (GAMEWIDTH * y);
	if (gameFeild[tempPosition] == 'X')
	{
		touchingItself = true;
	}
	else
	{
		touchingItself = false;
	}
	if (gameFeild[tempPosition] == 'A')
	{
		tailLength++;
		spawnApple(1);
	}
}

void moveSnake() {

	system("cls");

	posData[0] = position;

	for (int i = tailLength; i > 0; i--)
	{
		int l = i - 1;
		posData[i] = posData[l];
	}

	if (direction == 1 && position % GAMEWIDTH != 0) {
		x--;
		snakeTouching();
		position = x + (GAMEWIDTH * y);
		gameFeild[position] = 'X';
		gameFeild[posData[tailLength]] = ' ';
		printPlayfeild();
		Sleep(60);
	}
	else if (direction == 2 && position > GAMEWIDTH - 1) {
		y--;
		snakeTouching();
		position = x + (GAMEWIDTH * y);
		gameFeild[position] = 'X';
		gameFeild[posData[tailLength]] = ' ';
		printPlayfeild();
		Sleep(100);
	}
	else if (direction == 3 && (position + 1) % GAMEWIDTH != 0) {
		x++;
		snakeTouching();
		position = x + (GAMEWIDTH * y);
		gameFeild[position] = 'X';
		gameFeild[posData[tailLength]] = ' ';
		printPlayfeild();
		Sleep(60);
	}
	else if (direction == 4 && position < ARREYSIZE - GAMEWIDTH) {
		y++;
		snakeTouching();
		position = x + (GAMEWIDTH * y);
		gameFeild[position] = 'X';
		gameFeild[posData[tailLength]] = ' ';
		printPlayfeild();
		Sleep(100);
	}
	else
	{
		hasMoved = false;
	}
}

int main()
{
	bool dead = false;

	printPlayfeild();

	spawnApple(40);

	while (playing)
	{

		if (dead)
		{
			system("cls");
			cout << "Game Over" << endl << "Press TAB to restart";


			if (GetKeyState(VK_TAB) & 0x8000)
			{
				dead = false;
				restart();
			}
			else if (GetKeyState(VK_ESCAPE) & 0x8000)
			{
				playing = false;
			}
		}

		else
		{


			moveSnake();

			if (GetKeyState(VK_ESCAPE) & 0x8000)
			{
				system("cls");
				playing = false;
			}
			if (GetKeyState('A') & 0x8000 && direction != 3)
			{
				direction = 1;
			}
			if (GetKeyState('W') & 0x8000 && direction != 4)
			{
				direction = 2;
			}
			if (GetKeyState('D') & 0x8000 && direction != 1)
			{
				direction = 3;
			}
			if (GetKeyState('S') & 0x8000 && direction != 2)
			{
				direction = 4;
			}
			if (hasMoved == false)
			{
				dead = true;
			}
			if (touchingItself)
			{
				dead = true;
			}

		}
	}

	return 0;
}