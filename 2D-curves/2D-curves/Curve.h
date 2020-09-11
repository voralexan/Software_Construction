#pragma once
#include "Figures.h"
const double PI = 3.141592653589793;

class Curve	
{
public:
	virtual CurveSample* insert() = 0;
	virtual double calculateArea() = 0;
};
