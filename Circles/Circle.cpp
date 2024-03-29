#include <iostream>
#include "Circle.h"
#include <vector>
#include "Framework.h"
#include "Vector2.h"

Circle::Circle()
{
	//Randomise properties.
	radius = rand() % 30 + 11;

	pos = Vector2();

	pos.x = rand() % (gScreenWidth - (radius * 2));
	pos.y = rand() % (gScreenHeight - (radius * 2));
	
	dir = Vector2(rand() % 16 - 8, rand() % 16 - 8);

	alpha = 255;
	randomiseColour();

	bouncedThisFrame = false;
}

Circle::Circle(int redInput, int greenInput, int blueInput)
{
	radius = rand() % 30 + 11;

	pos = Vector2();

	pos.x = rand() % (gScreenWidth - (radius * 2));
	pos.y = rand() % (gScreenHeight - (radius * 2));

	dir = Vector2(rand() % 7 + 1, rand() % 7 + 1);

	red = redInput;
	green = greenInput;
	blue = blueInput;
	alpha = 255;

	bouncedThisFrame = false;
}

//Destructors and getters

Circle::~Circle() {};

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
	DrawCircle(pos.x, pos.y, radius);
}

void Circle::update()
{
	bouncedThisFrame = false;

	//Set colour
	ChangeColour(red, green, blue, alpha);
	pos.x += dir.x;
	pos.y += dir.y;

	//Collision Detection
	if (pos.x > gScreenWidth - (radius * 2) || pos.x < 0)
	{
		dir.x = -dir.x;
		bouncedThisFrame = true;
	}

	if (pos.y > gScreenHeight - (radius * 2) || pos.y < 0)
	{
		dir.y = -dir.y;
		bouncedThisFrame = true;
	}

	//1% Chance of reversing direction
	srand(time(0));
	int changeDirChance = rand() % 100;

	if (changeDirChance == 0)
	{
		dir.x = -dir.x;
		dir.y = -dir.y;
	}
}