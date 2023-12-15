#include"Vector2.h"

#pragma once

class Circle
{
public:
	Circle();
	Circle(int redInput, int greenInput, int blueInput);

	~Circle();

	Vector2 pos;
	Vector2 dir;

	bool bouncedThisFrame;

	int getRed();
	int getGreen();
	int getBlue();
	int getAlpha();

	void randomiseColour();
	
	void draw();
	void update();
private:
	int radius;

	int red;
	int blue;
	int green;
	int alpha;
};