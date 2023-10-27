/*
    Start shape drawing file
*/

#include <iostream>
#include "Framework.h"

// Variables with global scope - do not rename them, feel free to change values though

// Screen dimensions
int gScreenWidth{800};
int gScreenHeight{600};

// Delay to slow things down
int gTimeDelayMS{10};

using namespace std;

int main()
{
	cout << "Hello circles" << endl;

	struct Circles
	{
		int xPos;
		int yPos;
		int xDir;
		int yDir;
		int red;
		int blue;
		int green;
		int radius;
	};

	srand(time(0));
	Circles circleData[50];
	for (int i = 0; i < 50; i++)
	{
		//Radius.
		//circleData[i].radius = 30;
		circleData[i].radius = rand() % 30 + 11;
		//Position.
		circleData[i].xPos = rand() % (gScreenWidth - (circleData[i].radius * 2));
		circleData[i].yPos = rand() % (gScreenHeight - (circleData[i].radius * 2));

		//Speed control.
		circleData[i].xDir = rand() % 7 + 1;
		circleData[i].yDir = rand() % 7 + 1;

		//Colour values.
		circleData[i].red = rand() % 256;
		circleData[i].blue = rand() % 256;
		circleData[i].green = rand() % 256;
		
	}

	srand(time(0));
	while(UpdateFramework())
	{
		srand(time(0));
		for (int i = 0; i < 50; i++)
		{
			// Draws a circle at 100,200 with radius 20
			DrawCircle(circleData[i].xPos, circleData[i].yPos, circleData[i].radius);
			ChangeColour(circleData[i].red, circleData[i].blue, circleData[i].green, 255);
			circleData[i].xPos += circleData[i].xDir;
			circleData[i].yPos += circleData[i].yDir;

			if (circleData[i].xPos > gScreenWidth - (circleData[i].radius * 2) || circleData[i].xPos < 0)
			{
				circleData[i].xDir = -circleData[i].xDir;
			}

			if (circleData[i].yPos > gScreenHeight - (circleData[i].radius * 2) || circleData[i].yPos < 0)
			{
				circleData[i].yDir = -circleData[i].yDir;
			}

			srand(time(0));
			int changeDirChance = rand() % 100;

			if (changeDirChance == 0)
			{
				circleData[i].xDir = -circleData[i].xDir;
				circleData[i].yDir = -circleData[i].yDir;
			}
		}
	}

	cout << "Bye bye" << endl;

	return 0;
}
