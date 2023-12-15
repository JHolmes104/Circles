/*
    Start shape drawing file
*/

#include <iostream>
#include "Framework.h"
#include <vector>
#include "Circle.h"
#include "Vector2.h"

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

	//Randomise seed
	srand(time(NULL));

	//Create vector for circles
	vector<Circle> circleData;
	for (int i = 0; i < 50; i++)
	{
		Circle tempCircle = Circle();
		circleData.push_back(tempCircle);
	}

	while(UpdateFramework())
	{
		int newCircleNum = 0;


		for (Circle &circle: circleData)
		{
			// Draws a circle at its current location
			circle.draw();
			
			//Change circle's location
			circle.update();

			//Collision detection.
			if (circle.bouncedThisFrame == true)
			{
				newCircleNum++;
			}
		}

		//Check for user inputs to spawn in a new circle.
		if (IsButtonPressed(EButton::eRight))
		{
			if (rightClickHold == false)
			{
				Circle circle = Circle();
				GetMousePosition(circle.pos.x, circle.pos.y);
				circleData.push_back(circle);
			}
			rightClickHold = true;
		}
		//Prevent multiple circles spawning.
		else
		{
			rightClickHold = false;
		}

		//Spawn the correct number of circles depending on the number of collisions.
		for (int i = 0; i < newCircleNum; i++)
		{
			Circle tempCircle = Circle();
			circleData.push_back(tempCircle);
		}
	}

	cout << "Bye bye" << endl;

	return 0;
}
