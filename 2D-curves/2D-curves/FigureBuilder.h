#pragma once
#include "Circle.h"
#include "Ellipse.h"

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
		auto c = std::make_unique<Circle>(radius);
		sample = c->insert();
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

	 auto e = std::make_unique<Ellipse>(height,width);
	 sample = e->insert();
	 sample->curveFormula = "x^2 / " + std::to_string(height * height) + " + y^2 / " + std::to_string(width * width) + " = 1";
	 return sample;
	}
	
};

