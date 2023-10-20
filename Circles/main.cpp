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

	int r = 20;

	srand(time(0));
	int x = rand() % (gScreenWidth - (r * 2));
	int y = rand() % (gScreenHeight - (r * 2));

	int xDif = 2;
	int yDif = 3;

	while(UpdateFramework())
	{
		// Draws a circle at 100,200 with radius 20
		DrawCircle(x, y, r);
		x += xDif;
		y += yDif;

		if (x > gScreenWidth - (r * 2) || x < 0)
		{
			xDif = -xDif;
		}

		if (y > gScreenHeight - (r * 2) || y < 0)
		{
			yDif = -yDif;
		}

			//srand(time(0));
			//int changeDirChance = rand() % 100;

			//if (changeDirChance == 0)
			//{
				//circleData[i][2] = -circleData[i][2];
				//circleData[i][3] = -circleData[i][3];
			//}
	}

	cout << "Bye bye" << endl;

	return 0;
}
