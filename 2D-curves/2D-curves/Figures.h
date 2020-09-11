#pragma once

#include <string>
#include <iostream>
#include <vector>

struct CurveSample
{
	std::string curveFormula;
	double area;
	CurveSample() {
		area = 0;
		curveFormula = "";
	}
	CurveSample(std::string curveFormula, double area)
	{
		this->curveFormula = curveFormula;
		this->area = area;
	}
};

class Figures 
{
private:
	std::vector <CurveSample*> curvesArray;

public:
	Figures() {
	};
	~Figures() {

		for (auto i : curvesArray)
		{
				delete i;
		}
	};
	void insert();
	void generateRandomFigures(int amount);
	void print();	
	double getTotalArea();
	void sortByArea();
};




