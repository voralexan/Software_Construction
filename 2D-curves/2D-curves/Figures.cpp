
#include <algorithm>
#include <ctime>

#include "Figures.h"
#include"FigureBuilder.h"

void Figures::insert()
{
	int figureType;

	std::cout << "	Choose the figure: " << std::endl;
	std::cout << "	0 - Circle" << std::endl;
	std::cout << "	1 - Ellipse" << std::endl;
	std::cin >> figureType;
	switch (figureType)
	{
	case 0:
	{
		std::unique_ptr<CurveSample> sample = FigureBuilder::createCircle();
		curvesArray.push_back(std::move(sample));
		std::cout << "The equation: " << sample->curveFormula << "  has been added, its area = " << sample->area << std::endl;
		break;
	}
	case 1:
	{
		std::unique_ptr<CurveSample> sample = FigureBuilder::createEllipse();
		curvesArray.push_back(std::move(sample));
		std::cout << "The equation: " << sample->curveFormula << "  has been added, its area = " << sample->area << std::endl;
		break;
	}
	
	}
}



void Figures::generateRandomFigures(int amount)
{
	srand(std::time(nullptr));
	for (size_t i = 0; i < amount; i++)
	{
		std::unique_ptr<CurveSample> t;
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
			auto c = std::make_unique<Circle>(r);
						t = c->insert();
						t->curveFormula = "(x - " + std::to_string(a) + ")^2 + (y - " + std::to_string(b) + ")^2 = " + std::to_string(r * r);
						curvesArray.push_back(std::move(t));
					}
					case 1:
						int a = rand() % 25;
						int b = rand() % 25;
						auto e = std::make_unique<Ellipse>(a, b);
						t = e->insert();
						t->curveFormula = "x^2 / " + std::to_string(a * a) + " + y^2 / " + std::to_string(b * b) + " = 1";
						curvesArray.push_back(std::move(t));
		
		}
	}
}

void Figures::print()
{
	if (curvesArray.empty()) return;
	for (const auto& i : curvesArray)
	{
		std::cout << i->curveFormula << "		S = " << i->area << std::endl;
	}
}

struct sortByAreaRule
{
	bool operator()(const std::unique_ptr<CurveSample>& firstCurve, const std::unique_ptr<CurveSample>& secondCurve)
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
	for (const auto &i : curvesArray)
	{
		total += i->area;
	}
	return total;
}



