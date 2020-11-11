#pragma once
#include"Curve.h"
#include"Figures.h"

class CompoundObject : public Curve
{
	std::vector<CurveSample> objects;
public:
	void addObject(CurveSample object);
	double calculateArea();
	std::string defineFormula();
	std::unique_ptr<CurveSample> insert();
	CompoundObject();
	~CompoundObject();
};

