
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
		std::cout << "The equation: " << sample->curveFormula << "  has been added, its area = " << sample->area << std::endl;
		curvesArray.push_back(std::move(sample));
		break;
	}
	case 1:
	{
		std::unique_ptr<CurveSample> sample = FigureBuilder::createEllipse();
		std::cout << "The equation: " << sample->curveFormula << "  has been added, its area = " << sample->area << std::endl;
		curvesArray.push_back(std::move(sample));
		break;
	}

	}
}



void Figures::generateRandomFigures(int amount)
{
	srand(std::time(nullptr));
	for (size_t i = 0; i < amount; i++)
	{

		int figureType = rand() % 2;
		switch (figureType)
		{
		default:
			break;
		case 0:
		{
			std::unique_ptr<CurveSample> sample = FigureBuilder::randomCircle();
			curvesArray.push_back(std::move(sample));
		}
		case 1:
			std::unique_ptr<CurveSample> sample = FigureBuilder::randomEllipse();
			curvesArray.push_back(std::move(sample));

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
	for (const auto& i : curvesArray)
	{
		total += i->area;
	}
	return total;
}