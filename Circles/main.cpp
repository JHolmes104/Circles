/*
    Start shape drawing file
*/

#include <iostream>
#include "Framework.h"
#include <vector>
#include "Circle.h"

// Variables with global scope - do not rename them, feel free to change values though

// Screen dimensions
int gScreenWidth{800};
int gScreenHeight{600};

// Delay to slow things down
int gTimeDelayMS{10};

bool rightClickHold = false;

using namespace std;

int main()
{
	cout << "Hello circles" << endl;

	

	srand(time(0));
	vector<Circle> circleData;
	for (int i = 0; i < 50; i++)
	{
		Circle tempCircle = Circle();
		circleData.push_back(tempCircle);
	}
	srand(time(0));
	while(UpdateFramework())
	{
		srand(time(0));
		for (Circle &circle: circleData)
		{
			// Draws a circle at 100,200 with radius 20
			DrawCircle(circle.xPos, circle.yPos, circle.radius);
			ChangeColour(circle.getRed(), circle.getGreen(), circle.getBlue(), circle.getAlpha());
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
		}

		if (IsButtonPressed(EButton::eRight))
		{
			if (rightClickHold == false)
			{
				Circle circle = Circle();
				GetMousePosition(circle.xPos, circle.yPos);
				circleData.push_back(circle);
			}
			rightClickHold = true;
		}
		else
		{
			rightClickHold = false;
		}
	}

	cout << "Bye bye" << endl;

	return 0;
}
