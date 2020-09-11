#pragma once

#include <string>
#include <iostream>
#include <vector>

struct TNote             // запись о кривой
{
	std::string str;		//кривая в виде строки	
	double area;			//площадь кривой
	TNote() {}
	TNote(std::string _str, double _area)
	{
		str = _str;
		area = _area;
	}
};

class Figures 
{
private:
	std::vector <TNote*> List_curves;	//вектор, в котором хранятся кривые

public:
	Figures() {
	};
	~Figures() {

		for (auto i : List_curves)
		{
				delete i;
		}
	};
	void Insert();					// добавление новой кривой
	void GenerateRandomFigures(int amount);
	void Print();					//вывод списка таблиц на экран	
	double Total_area();			//общая площадь
	void Sort();					//сортировка записей
};




