
#include <algorithm>
#include <ctime>
#include "Figures.h"
#include "Circle.h"
#include "Ellipse.h"

Figures::Figures()
{
}

Figures::~Figures()
{
	List_curves.clear();
}
void Figures::Insert()	//добавление новой кривой
{
	char n;
	std::string str_r, str_a, str_b, str_x0, str_y0;
	double r = 0, a = 0, b = 0;
	double x0, y0;
	TNote *t;
	std::cout << "	Choose the figure: " << std::endl;
	std::cout << "	a - Circle" << std::endl;
	std::cout << "	b - Ellipse" << std::endl;
	std::cin >> n;
	if (n == 'a')
	{		
		std::cout << "Circle equation: (x - x0)^2 + (y - y0)^2 = r^2" << std::endl;
		std::cout << "Enter x0, y0, r" << std::endl;
		std::cin >> str_x0 >> str_y0 >> str_r;
		x0 = atof(str_x0.c_str());
		y0 = atof(str_y0.c_str());
		r = atof(str_r.c_str());
		if ((x0 == 0 && str_x0 != "0")|| (y0 == 0 && str_y0 != "0") || (r <= 0 && str_r != "0"))
			throw("Error: Incorrect arguments");
		Shape* c = new Circle(r);
		t = c->Insert();
		t->str = "(x - " + str_x0 + ")^2 + (y - " + str_y0 + ")^2 = " + std::to_string(r * r);
		List_curves.push_back(t);	//добавление кривой в вектор	
		std::cout <<"The equation: "<< t->str <<"  has been added, its area = " << t->area << std::endl;
	}
	else if (n == 'b')	
	{
		std::cout << "Ellipse equation: x^2 / a^2 + y^2 / b^2 = 1" << std::endl;
		std::cout << "Enter the parameter a: " << std::endl;
		std::cin >> str_a;
		std::cout << "Enter the parameter b: " << std::endl;
		std::cin >> str_b;
		a = atof(str_a.c_str());
		b = atof(str_b.c_str());
		if (a == 0 || b == 0)
			throw("Error: Incorrect arguments");
		Shape* e = new Ellipse(a, b);
		t = e->Insert();
		t->str = "x^2 / " + std::to_string(a * a) + " + y^2 / " + std::to_string(b * b) + " = 1";
		List_curves.push_back(t);	//добавление кривой в вектор
		std::cout << "The equation: " << t->str << "  has been added, its area = " << t->area << std::endl;
	}
	else throw ("Wrong enter");
}

void Figures::GenerateRandomFigures(int amount)
{
	srand(std::time(nullptr));
	for (size_t i = 0; i < amount; i++)
	{
		TNote* t;
		int figureType = rand()%2;
		switch (figureType)
		{
		default:
			break;
		case 0:
		{
			int a = rand() % 25;
			int b = rand() % 25;
			int r = rand() % 25; 
			Shape* c = new Circle(r
);
			t = c->Insert();
			t->str = "(x - " + std::to_string(a) + ")^2 + (y - " + std::to_string(b) + ")^2 = " + std::to_string(r * r);
			List_curves.push_back(t);
		}
		case 1:
			int a = rand() % 25;
			int b = rand() % 25;
			Shape * e = new Ellipse(a,b);
			t = e->Insert();
			t->str = "x^2 / " + std::to_string(a * a) + " + y^2 / " + std::to_string(b * b) + " = 1";
			List_curves.push_back(t);
		}
	}
}

void Figures::Print()		//вывод кривых на экран
{
	if (List_curves.empty()) return;
	for (auto  i : List_curves)
	{
		std::cout << i->str << "		S = " << i->area << std::endl;
	}
}

struct rule				//правило, по которому выполняется сортировка
{
	bool operator()(TNote * dot1, TNote* dot2)
	{
		return dot1->area < dot2->area;
	}
};

void Figures::Sort()	//сортировка элементов вектора
{
	if (List_curves.empty()) 
		return;
	std::sort(List_curves.begin(), List_curves.end(), rule());
}

double Figures::Total_area()	//подсчёт общей площади
{
	if (List_curves.empty()) return 0;
	double total = 0;
	for (auto i : List_curves)
	{
		total += i->area;
	}
	return total;
}



