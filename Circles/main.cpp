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


	srand(time(0));
	int circleData[100][8];
	for (int i = 0; i < 100; i++)
	{
		//Radius. 
		circleData[i][7] = rand() % 30 + 11;

		//Position.
		circleData[i][0] = rand() % (gScreenWidth - (circleData[i][7] * 2));
		circleData[i][1] = rand() % (gScreenHeight - (circleData[i][7] * 2));

		//Speed control.
		circleData[i][2] = rand() % 10 + 1;
		circleData[i][3] = rand() % 10 + 1;

		//Colour values.
		circleData[i][4] = rand() % 256;
		circleData[i][5] = rand() % 256;
		circleData[i][6] = rand() % 256;
		
	}

	srand(time(0));
	while(UpdateFramework())
	{
		srand(time(0));
		for (int i = 0; i < 100; i++)
		{
			// Draws a circle at 100,200 with radius 20
			DrawCircle(circleData[i][0], circleData[i][1], circleData[i][7]);
			ChangeColour(circleData[i][4], circleData[i][5], circleData[i][6], 255);
			circleData[i][0] += circleData[i][2];
			circleData[i][1] += circleData[i][3];

			if (circleData[i][0] > gScreenWidth - (circleData[i][7] * 2) || circleData[i][0] < 0)
			{
				circleData[i][2] = -circleData[i][2];
			}

			if (circleData[i][1] > gScreenHeight - (circleData[i][7] * 2) || circleData[i][1] < 0)
			{
				circleData[i][3] = -circleData[i][3];
			}

			srand(time(0));
			int changeDirChance = rand() % 100;

			if (changeDirChance == 0)
			{
				circleData[i][2] = -circleData[i][2];
				circleData[i][3] = -circleData[i][3];
			}
		}
	}

	cout << "Bye bye" << endl;

	return 0;
}
