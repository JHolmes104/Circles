#pragma once
class Circle
{
public:
	int xPos;
	int yPos;
	int xDir;
	int yDir;
	int radius;
	
	Circle();
	Circle(int redInput, int greenInput, int blueInput);

	int getRed();
	int getGreen();
	int getBlue();
	int getAlpha();
private:
	int screenWidth;
	int screenHeight;
	int red;
	int blue;
	int green;
	int alpha;
};