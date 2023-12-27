#pragma once

#include"pch.h"
#include"Velocity.h"
#include"Point.h"


class COLLISIONDETECTIONALGO_API CollisionDetection
{

public:

	CollisionDetection();
	~CollisionDetection();
	void setPointFirst(Point p);
	void setPointSecond(Point p);
	void setVelocityFirst(Velocity v);
	void setVelocitySecond(Velocity v);
	Point PointFirst();
	Point PointSecond();
	Point CollisionPoint();
	void findCollisionPoint();



private:

	Point mPointFirst;
	Point mPointSecond;
	Point mCollisionPoint;
	Velocity mVelocityFirst;
	Velocity mVelocitySecond;
};

