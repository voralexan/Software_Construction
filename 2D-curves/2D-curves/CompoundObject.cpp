#include "CompoundObject.h"




void CompoundObject::addObject(CurveSample object)
{
	objects.push_back(object);
}

double CompoundObject::calculateArea()
{
	if (objects.empty()) return 0;
	double total = 0;
	for (auto i : objects)
	{
		total += i.area;
	}
	return total;
}

std::string CompoundObject::defineFormula()
{
	if (objects.empty()) return "";
	std::string formula;
	int counter = 0;
	formula.append("\n        Compound object. It contains : \n");

	for (auto i : objects)
	{
		counter++;
		formula.append("        " + std::to_string(counter) + ". ");
		formula.append(i.curveFormula);
		formula.append("\n");

	}
	return formula;
}

std::unique_ptr<CurveSample> CompoundObject::insert()
{
	auto p = std::make_unique<CurveSample>();
	p->curveFormula = defineFormula();
	p->area = calculateArea();
	return p;
	return std::unique_ptr<CurveSample>();
}


CompoundObject::CompoundObject()
{
}


CompoundObject::~CompoundObject()
{
}
