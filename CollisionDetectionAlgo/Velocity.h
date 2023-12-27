#pragma once
#include"pch.h"
class COLLISIONDETECTIONALGO_API Velocity
{
public:
	Velocity();
	Velocity(double x, double y);
	~Velocity();
	void setX(double x);
	void setY(double y);
	double X();
	double Y();

private:
	double mX;
	double mY;
	double mMag;
};

