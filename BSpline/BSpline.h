#pragma once
#include "pch.h"

#include <vector>
#include <utility>
#include "Point.h"

class BSPLINE_API BSpline {
public:
	BSpline(int degree);
	std::vector<Point> evaluate(std::vector<Point> control_points, float t);
private:
	int mDegree;
	std::vector<float> generateUniformKnots(int num_control_points);
	float bSplineBasis(int i, int k, float t, const std::vector<float>& knots);
};

