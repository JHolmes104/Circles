#include <iostream>
#include "Circle.h"
#include <vector>

Circle::Circle()
{
	screenWidth = 800;
	screenHeight = 600;
	
	radius = rand() % 30 + 11;

	xPos = rand() % (screenWidth - (radius * 2));
	yPos = rand() % (screenHeight - (radius * 2));

	xDir = rand() % 7 + 1;
	yDir = rand() % 7 + 1;

	red = 255;
	green = 0;
	blue = 0;
	alpha = 255;
}

Circle::Circle(int redInput, int greenInput, int blueInput)
{
	screenWidth = 800;
	screenHeight = 600;

	radius = rand() % 30 + 11;

	xPos = rand() % (screenWidth - (radius * 2));
	yPos = rand() % (screenHeight - (radius * 2));

	xDir = rand() % 7 + 1;
	yDir = rand() % 7 + 1;

	red = redInput;
	green = greenInput;
	blue = blueInput;
	alpha = 255;
}

int Circle::getRed(){ return red; }

int Circle::getGreen() { return green; }

int Circle::getBlue() { return blue; }

int Circle::getAlpha() { return alpha; }