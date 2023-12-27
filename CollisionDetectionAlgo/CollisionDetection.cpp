#include "pch.h"
#include "CollisionDetection.h"



CollisionDetection::CollisionDetection()
{

}

CollisionDetection::~CollisionDetection()
{

}

void CollisionDetection::setPointFirst(Point p)
{
	mPointFirst = p;
}
void CollisionDetection::setPointSecond(Point p)
{
	mPointSecond = p;
}

Point CollisionDetection::PointFirst()
{
	return mPointFirst;
}
Point CollisionDetection::PointSecond()
{
	return mPointSecond;
}
Point CollisionDetection::CollisionPoint()
{
	return mCollisionPoint;
}

void CollisionDetection::setVelocityFirst(Velocity v)
{
	mVelocityFirst = v;
}
void CollisionDetection::setVelocitySecond(Velocity v)
{
	mVelocitySecond = v;
}

void CollisionDetection::findCollisionPoint()
{
	double Time = (mPointSecond.X() - mPointFirst.X()) / (mVelocityFirst.X() - mVelocitySecond.X());



	mCollisionPoint.setX(mPointFirst.X() + (mVelocityFirst.X() * Time));
	mCollisionPoint.setY(mPointFirst.Y() + (mVelocityFirst.Y() * Time));

}
