// CollisionDetectionAlgo.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "CollisionDetectionAlgo.h"


// This is an example of an exported variable
COLLISIONDETECTIONALGO_API int nCollisionDetectionAlgo=0;

// This is an example of an exported function.
COLLISIONDETECTIONALGO_API int fnCollisionDetectionAlgo(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CollisionDetectionAlgo::CollisionDetectionAlgo()
{
    return;
}
