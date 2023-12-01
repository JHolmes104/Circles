#pragma once
class Circle
{
public:
	Circle();
	Circle(int redInput, int greenInput, int blueInput);


	int xPos;
	int yPos;

	int getRed();
	int getGreen();
	int getBlue();
	int getAlpha();

	void draw();
	void update();
private:
	int xPos;
	int yPos;

	int xDir;
	int yDir;

	int radius;

	int red;
	int blue;
	int green;
	int alpha;
};