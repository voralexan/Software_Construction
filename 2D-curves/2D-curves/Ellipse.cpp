#include "Figures.h"
#include "Ellipse.h"


CurveSample * Ellipse::insert()
{
	double S;
	CurveSample *p = new CurveSample;
	p->area = calculateArea();
	return p;
}

double Ellipse::calculateArea() {
	return  PI * height * width;
}