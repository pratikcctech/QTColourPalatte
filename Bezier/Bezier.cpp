#include "pch.h"

#include "Bezier.h"
#include <cmath>

//the constructor of the bezier class
Bezier::Bezier(Point inP0, Point inP1, Point inP2, Point inP3) :
    mP0(inP0),
    mP1(inP1),
    mP2(inP2),
    mP3(inP2)
{

}
Bezier::~Bezier()
{

}
//the implementation of the Bezier curve algorithm function
void Bezier::drawCurve(Point inP0, Point inP1, Point inP2, Point inP3, std::vector<float>& mVertices, std::vector<float>& mColors)
{
    for (float t = 0; t <= 1; t += 0.001)
    {

        float x = pow(1 - t, 3) * inP0.X() + 3 * pow(1 - t, 2) * t * inP1.X() + 3 * (1 - t) * pow(t, 2) * inP2.X() + pow(t, 3) * inP3.X();
        float y = pow(1 - t, 3) * inP0.Y() + 3 * pow(1 - t, 2) * t * inP1.Y() + 3 * (1 - t) * pow(t, 2) * inP2.Y() + pow(t, 3) * inP3.Y();


        mVertices.push_back(x);
        mVertices.push_back(y);


        mVertices.push_back(x);
        mVertices.push_back(y);


        mColors.push_back(0.0f);
        mColors.push_back(1.0f);
        mColors.push_back(0.0f);

        mColors.push_back(0.0f);
        mColors.push_back(1.0f);
        mColors.push_back(0.0f);

    }

}