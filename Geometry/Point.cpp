#include "pch.h"
#include "Point.h"


Point::Point()
{
	mX = 0;
	mY = 0;

}
Point::Point(double x, double y)
{
	mX = x;
	mY = y;
}
Point::~Point()
{

}

void Point::setX(double x)
{
	mX = x;
}
void Point::setY(double y)
{
	mY = y;
}

double Point::X()
{
	return mX;
}
double Point::Y()
{
	return mY;
}