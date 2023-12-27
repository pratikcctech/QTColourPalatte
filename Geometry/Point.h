#pragma once
#include "pch.h"

class  GEOMETRY_API Point
{

public:
	Point();
	Point(double x, double y);
	~Point();
	double  X();
	double  Y();
	void setX(double x);
	void setY(double y);

private:

	double mX;
	double mY;
};

