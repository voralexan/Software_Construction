
#include <algorithm>
#include <ctime>

#include "Figures.h"
#include "Circle.h"
#include "Ellipse.h"

void Figures::insert()
{
	int figureType;
	CurveSample* sample;
	std::cout << "	Choose the figure: " << std::endl;
	std::cout << "	0 - Circle" << std::endl;
	std::cout << "	1 - Ellipse" << std::endl;
	std::cin >> figureType;
	switch (figureType)
	{
	default:
		break;
	case 0:
	{
		double x0, y0, radius;
		std::cout << "Circle equation: (x - x0)^2 + (y - y0)^2 = r^2" << std::endl;
		std::cout << "Enter x0, y0, r" << std::endl;
		std::cin >> x0 >> y0 >> radius;
		if (x0 <= 0 || y0 <= 0  || radius <= 0)
			throw("Error: Incorrect arguments");
		Curve* c = new Circle(radius);
		sample = c->insert();
		sample->curveFormula = "(x - " + std::to_string(x0) + ")^2 + (y - " + std::to_string(y0) + ")^2 = " + std::to_string(radius * radius);
		curvesArray.push_back(sample);
		delete c;
		std::cout << "The equation: " << sample->curveFormula << "  has been added, its area = " << sample->area << std::endl;
	}
	case 1:
	{
		double height = 0, width = 0;
		std::cout << "Ellipse equation: x^2 / a^2 + y^2 / b^2 = 1" << std::endl;
		std::cout << "Enter the parameter a: " << std::endl;
		std::cin >> height;
		std::cout << "Enter the parameter b: " << std::endl;
		std::cin >> width;
		if ( height<=0 ||  width <= 0 )
			throw("Error: Incorrect arguments");
	
		Curve* e = new Ellipse(height, width);
		sample = e->insert();
		sample->curveFormula = "x^2 / " + std::to_string(height * height) + " + y^2 / " + std::to_string(width * width) + " = 1";
		curvesArray.push_back(sample);
		delete e;
		std::cout << "The equation: " << sample->curveFormula << "  has been added, its area = " << sample->area << std::endl;
	}
	
	}
}



void Figures::generateRandomFigures(int amount)
{
	srand(std::time(nullptr));
	for (size_t i = 0; i < amount; i++)
	{
		CurveSample* t;
		int figureType = rand() % 2;
		switch (figureType)
		{
		default:
			break;
		case 0:
		{
			int a = rand() % 25;
			int b = rand() % 25;
			int r = rand() % 25;
			Curve* c = new Circle(r);
			t = c->insert();
			t->curveFormula = "(x - " + std::to_string(a) + ")^2 + (y - " + std::to_string(b) + ")^2 = " + std::to_string(r * r);
			curvesArray.push_back(t);
			delete c;
		}
		case 1:
			int a = rand() % 25;
			int b = rand() % 25;
			Curve* e = new Ellipse(a, b);
			t = e->insert();
			t->curveFormula = "x^2 / " + std::to_string(a * a) + " + y^2 / " + std::to_string(b * b) + " = 1";
			curvesArray.push_back(t);
			delete e;
		}
	}
}

void Figures::print()
{
	if (curvesArray.empty()) return;
	for (auto i : curvesArray)
	{
		std::cout << i->curveFormula << "		S = " << i->area << std::endl;
	}
}

struct sortByAreaRule
{
	bool operator()(CurveSample* firstCurve, CurveSample* secondCurve)
	{
		return firstCurve->area < secondCurve->area;
	}
};

void Figures::sortByArea()
{
	if (curvesArray.empty())
		return;
	std::sort(curvesArray.begin(), curvesArray.end(), sortByAreaRule());
}

double Figures::getTotalArea()
{
	if (curvesArray.empty()) return 0;
	double total = 0;
	for (auto i : curvesArray)
	{
		total += i->area;
	}
	return total;
}



