#include "pch.h"
#include "Velocity.h"


Velocity::Velocity()
{

}

Velocity::~Velocity()
{

}

void Velocity::setX(double x)
{
	mX = x;
}

void Velocity::setY(double y)
{
	mY = y;
}

double Velocity::X()
{
	return mX;
}
double Velocity::Y()
{
	return mY;
}

Velocity::Velocity(double x, double y)
{
	mX = x;
	mY = y;

}