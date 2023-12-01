#include <iostream>
#include "Circle.h"
#include <vector>
#include "Framework.h"

Circle::Circle()
{
	radius = rand() % 30 + 11;

	xPos = rand() % (gScreenWidth - (radius * 2));
	yPos = rand() % (gScreenHeight - (radius * 2));

	xDir = rand() % 7 + 1;
	yDir = rand() % 7 + 1;

	alpha = 255;
	randomiseColour();
}

Circle::Circle(int redInput, int greenInput, int blueInput)
{
	radius = rand() % 30 + 11;

	xPos = rand() % (gScreenWidth - (radius * 2));
	yPos = rand() % (gScreenHeight - (radius * 2));

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

void Circle::randomiseColour()
{
	red = rand() % 256;
	green = rand() % 256;
	blue = rand() % 256;
}

void Circle::draw()
{
	DrawCircle(xPos, yPos, radius);
}

void Circle::update()
{
	ChangeColour(red, green, blue, alpha);
	xPos += xDir;
	yPos += yDir;

	if (xPos > gScreenWidth - (radius * 2) || xPos < 0)
	{
		xDir = -xDir;
	}

	if (yPos > gScreenHeight - (radius * 2) || yPos < 0)
	{
		yDir = -yDir;
	}

	srand(time(0));
	int changeDirChance = rand() % 100;

	if (changeDirChance == 0)
	{
		xDir = -xDir;
		yDir = -yDir;
	}
}