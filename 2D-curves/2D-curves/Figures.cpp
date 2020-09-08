#include "Figures.h"
#include <algorithm>
#include "Circle.h"
#include "Ellipse.h"

Figures::Figures()
{
	length = 0;
}

Figures::~Figures()
{
	List_curves.clear();
	length = 0;
}
void Figures::Insert()	//добавление новой кривой
{
	char n;
	string str_r, str_a, str_b, str_x0, str_y0;
	double r = 0, a = 0, b = 0;
	double x0, y0;
	TNote *t;
	cout << "	Choose the figure: " << endl;
	cout << "	a - Circle" << endl;
	cout << "	b - Ellipse" << endl;
	cin >> n;
	if (n == 'a')
	{		
		cout << "Circle equation: (x - x0)^2 + (y - y0)^2 = r^2" << endl;
		cout << "Enter x0, y0, r" << endl;
		cin >> str_x0 >> str_y0 >> str_r;
		x0 = atof(str_x0.c_str());
		y0 = atof(str_y0.c_str());
		r = atof(str_r.c_str());
		if ((x0 == 0 && str_x0 != "0")|| (y0 == 0 && str_y0 != "0") || (r <= 0 && str_r != "0"))
			throw("Error: Incorrect arguments");
		Shape* c = new Circle(r);
		t = c->Insert();
		t->str = "(x - " + str_x0 + ")^2 + (y - " + str_y0 + ")^2 = " + to_string(r * r);
		List_curves.push_back(t);	//добавление кривой в вектор
		length++;		
		cout <<"The equation: "<< t->str <<"  has been added, its area = " << t->area << endl;
	}
	else if (n == 'b')	
	{
		cout << "Ellipse equation: x^2 / a^2 + y^2 / b^2 = 1" << endl;
		cout << "Enter the parameter a: " << endl;
		cin >> str_a;
		cout << "Enter the parameter b: " << endl;
		cin >> str_b;
		a = atof(str_a.c_str());
		b = atof(str_b.c_str());
		if (a == 0 || b == 0)
			throw("Error: Incorrect arguments");
		Shape* e = new Ellipse(a, b);
		t = e->Insert();
		t->str = "x^2 / " + to_string(a * a) + " + y^2 / " + to_string(b * b) + " = 1";
		length++;
		List_curves.push_back(t);	//добавление кривой в вектор
		cout << "The equation: " << t->str << "  has been added, its area = " << t->area << endl;
	}
	else throw ("Wrong enter");
}

void Figures::Print()		//вывод кривых на экран
{
	if (length == 0) throw ("The list of curves is empty");
	for (int i = 0; i < length; i++)
	{
		TNote *t = List_curves[i];
		cout << t->str << "		S = " << t->area << endl;
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
	if (length == 0) throw ("The list of curves is empty");
	std::sort(List_curves.begin(), List_curves.end(), rule());
}

double Figures::Total_area()	//подсчёт общей площади
{
	if (length == 0) return 0;
	double total = 0;
	for (int i = 0; i < length; i++)
	{
		total += List_curves[i]->area;
	}
	return total;
}



