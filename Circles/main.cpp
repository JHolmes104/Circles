/*
    Start shape drawing file
*/

#include <iostream>
#include "Framework.h"
#include <vector>

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
		int circleNum;
	};

	int currentCircleNum = 0;
	srand(time(0));
	vector<Circles> circleData;
	for (int i = 0; i < 50; i++)
	{
		Circles tempCircle;
		//Radius.
		tempCircle.radius = rand() % 30 + 11;
		//Position.
		tempCircle.xPos = rand() % (gScreenWidth - (tempCircle.radius * 2));
		tempCircle.yPos = rand() % (gScreenHeight - (tempCircle.radius * 2));

		//Speed control.
		tempCircle.xDir = rand() % 7 + 1;
		tempCircle.yDir = rand() % 7 + 1;

		//Colour values.
		tempCircle.red = rand() % 256;
		tempCircle.blue = rand() % 256;
		tempCircle.green = rand() % 256;

		tempCircle.circleNum = currentCircleNum;
		currentCircleNum++;

		circleData.push_back(tempCircle);
	}
	srand(time(0));
	while(UpdateFramework())
	{
		srand(time(0));
		for (Circles &circle: circleData)
		{
			// Draws a circle at 100,200 with radius 20
			DrawCircle(circle.xPos, circle.yPos, circle.radius);
			ChangeColour(circle.red, circle.blue, circle.green, 255);
			circle.xPos += circle.xDir;
			circle.yPos += circle.yDir;

			if (circle.xPos > gScreenWidth - (circle.radius * 2) || circle.xPos < 0)
			{
				circle.xDir = -circle.xDir;
			}

			if (circle.yPos > gScreenHeight - (circle.radius * 2) || circle.yPos < 0)
			{
				circle.yDir = -circle.yDir;
			}

			srand(time(0));
			int changeDirChance = rand() % 100;

			if (changeDirChance == 0)
			{
				circle.xDir = -circle.xDir;
				circle.yDir = -circle.yDir;
			}

			for (Circles& circle2 : circleData)
			{
				if (circle2.circleNum != circle.circleNum)
				{
					int totalRad = circle2.radius + circle.radius;
					int xDif = circle2.xPos - circle.xPos;
					int yDif = circle2.yPos - circle.yPos;

					if (totalRad > xDif)
					{
						circle.xDir = -circle.xDir;
						circle2.xDir = -circle2.xDir;
					}

					if (totalRad > yDif)
					{
						circle.yDir = -circle.yDir;
						circle2.yDir = -circle2.yDir;
					}
				}
			}
		}
	}

	cout << "Bye bye" << endl;

	return 0;
}
