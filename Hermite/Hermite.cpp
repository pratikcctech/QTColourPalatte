#include "pch.h"

#include "Hermite.h"


//constructor of the Hermite Class
Hermite::Hermite(Point inP0, Point inP1, Point inP2, Point inP3) :
    mP0(inP0),
    mP1(inP1),
    mP2(inP2),
    mP3(inP2)
{

}
Hermite::~Hermite()
{

}


//the implementation of the harmite curve algorithm function
void Hermite::drawCurve(Point inP0, Point inP1, Point inP2, Point inP3, vector<float>& mVertices, vector<float>& mColors)
{
    float t;
    float t2;
    float t3;
    for (t = 0; t <= 1; t += 0.001)
    {
        t2 = t * t;
        t3 = t2 * t;

        blend1 = (2 * t3) - (3 * t2) + 1;
        blend2 = (-2 * t3) + (3 * t2);
        blend3 = t3 - (2 * t2) + t;
        blend4 = t3 - t2;

        float x = blend1 * inP0.X() + blend2 * (inP1.X() - inP0.X()) + blend3 * inP2.X() + blend4 * (inP3.X() - inP2.X());
        float y = blend1 * inP0.Y() + blend2 * (inP1.Y() - inP0.Y()) + blend3 * inP2.Y() + blend4 * (inP3.Y() - inP2.Y());


        mVertices.push_back(x);
        mVertices.push_back(y);



        mColors.push_back(0.0f);
        mColors.push_back(1.0f);
        mColors.push_back(0.0f);

        mVertices.push_back(x);
        mVertices.push_back(y);


        mColors.push_back(0.0f);
        mColors.push_back(1.0f);
        mColors.push_back(0.0f);


    }

}

