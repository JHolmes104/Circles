/*
    Start shape drawing file
*/

#include <SFML/System/Clock.hpp>
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
		int red;
		int blue;
		int green;
		int radius;
	};

	vector<Circles> circleData;
	Circles tempCircle;

	//Radius.
	tempCircle.radius = rand() % 30 + 11;

	//Position.
	tempCircle.xPos = rand() % (gScreenWidth - (tempCircle.radius * 2));
	tempCircle.yPos = rand() % (gScreenHeight - (tempCircle.radius * 2));



	//Colour values.
	tempCircle.red = rand() % 256;
	tempCircle.blue = rand() % 256;
	tempCircle.green = rand() % 256;
	circleData.push_back(tempCircle);


	sf::Clock clock;

	sf::Time timeLastCircleWasPlaced = sf::seconds(0.0f);
	srand(time(0));
	while(UpdateFramework())
	{
		srand(time(0));
		if (IsButtonPressed(EButton::eLeft))
		{
			if (IsButtonPressed(EButton::eRight))
			{
				sf::Time currentTime = clock.getElapsedTime();
				float timeDif = (currentTime - timeLastCircleWasPlaced).asSeconds();
				if (timeDif >= 0.3f)
				{
					tempCircle.radius = rand() % 30 + 11;

					GetMousePosition(tempCircle.xPos, tempCircle.yPos);

					//Colour values.
					tempCircle.red = rand() % 256;
					tempCircle.blue = rand() % 256;
					tempCircle.green = rand() % 256;
					circleData.push_back(tempCircle);

					timeLastCircleWasPlaced = currentTime;
				}
			}
			else
			{
				GetMousePosition(circleData[0].xPos, circleData[0].yPos);
			}


			// Draws a circle at 100,200 with radius 20
			DrawCircle(circleData[0].xPos, circleData[0].yPos, circleData[0].radius);
			ChangeColour(circleData[0].red, circleData[0].blue, circleData[0].green, 255);
		}

		for (Circles& circle : circleData)
		{
			// Draws a circle at 100,200 with radius 20
			DrawCircle(circle.xPos, circle.yPos, circle.radius);
			ChangeColour(circle.red, circle.blue, circle.green, 255);
		}
	}

	cout << "Bye bye" << endl;

	return 0;
}
