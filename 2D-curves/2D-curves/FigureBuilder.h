#pragma once
#include "Circle.h"
#include "Ellipse.h"
#include "CompoundObject.h"

class FigureBuilder
{

	FigureBuilder() {};
public:
	static std::unique_ptr<CurveSample> createCircle() {
		std::unique_ptr<CurveSample> sample;
		double x0, y0, radius;
		std::cout << "Circle equation: (x - x0)^2 + (y - y0)^2 = r^2" << std::endl;
		std::cout << "Enter x0, y0, r" << std::endl;
		std::cin >> x0 >> y0 >> radius;
		if (x0 <= 0 || y0 <= 0 || radius <= 0)
			throw("Error: Incorrect arguments");
		auto circle = std::make_unique<Circle>(radius);
		sample = circle->insert();
		sample->curveFormula = "(x - " + std::to_string(x0) + ")^2 + (y - " + std::to_string(y0) + ")^2 = " + std::to_string(radius * radius);
		return sample;
	}

	static std::unique_ptr<CurveSample> createEllipse() {
		std::unique_ptr<CurveSample> sample;
		double height = 0, width = 0;
		std::cout << "Ellipse equation: x^2 / a^2 + y^2 / b^2 = 1" << std::endl;
		std::cout << "Enter the parameter a: " << std::endl;
		std::cin >> height;
		std::cout << "Enter the parameter b: " << std::endl;
		std::cin >> width;
		if (height <= 0 || width <= 0)
			throw("Error: Incorrect arguments");

		auto ellipse = std::make_unique<Ellipse>(height, width);
		sample = ellipse->insert();
		sample->curveFormula = "x^2 / " + std::to_string(height * height) + " + y^2 / " + std::to_string(width * width) + " = 1";
		return sample;
	}

	static std::unique_ptr<CurveSample> createCompound() {
		std::unique_ptr<CurveSample> sample;
		auto object = std::make_unique<CompoundObject>();
		int figureType;
		do {
			std::cout << "	0 - Exit" << std::endl;
			std::cout << "	Choose the figure: " << std::endl;
			std::cout << "	1 - Circle" << std::endl;
			std::cout << "	2 - Ellipse" << std::endl;
			std::cin >> figureType;
			switch (figureType)
			{
			case 1:
			{
				std::unique_ptr<CurveSample> circle = createCircle();
				std::cout << "The equation: " << circle->curveFormula << "  has been added, its area = " << circle->area << std::endl;
				object->addObject(*circle.get());
				break;
			}
			case 2:
			{
				std::unique_ptr<CurveSample> ellipse = createEllipse();
				std::cout << "The equation: " << ellipse->curveFormula << "  has been added, its area = " << ellipse->area << std::endl;
				object->addObject(*ellipse.get());
				break;
			}
			}
		} while (figureType != 0);
		sample = object->insert();
		
		return sample;
	}

	static std::unique_ptr<CurveSample> randomEllipse() {
		std::unique_ptr<CurveSample> sample;
		int height = rand() % 25;
		int width = rand() % 25;
		auto ellipse = std::make_unique<Ellipse>(height, width);
		sample = ellipse->insert();
		sample->curveFormula = "x^2 / " + std::to_string(height * height) + " + y^2 / " + std::to_string(width * width) + " = 1";
		return sample;
	}

	static std::unique_ptr<CurveSample> randomCircle() {
		std::unique_ptr<CurveSample> sample;
		int x0 = rand() % 25;
		int y0 = rand() % 25;
		int radius = rand() % 25;
		auto circle = std::make_unique<Circle>(radius);
		sample = circle->insert();
		sample->curveFormula = "(x - " + std::to_string(x0) + ")^2 + (y - " + std::to_string(y0) + ")^2 = " + std::to_string(radius * radius);
		return sample;
	}

};

