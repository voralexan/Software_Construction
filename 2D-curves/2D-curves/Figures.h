#pragma once

#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct TNote             // запись о кривой
{
	string str;		//кривая в виде строки	
	double area;	//площадь кривой
	TNote() {}
	TNote(string _str, double _area)
	{
		str = _str;
		area = _area;
	}
};

class Figures 
{
private:
	vector <TNote*> List_curves;	//вектор, в котором хранятся кривые
protected:
	unsigned int length;         // количество записей в таблице
public:
	Figures();
	~Figures();
	void Insert();					// добавление новой кривой
	void Print();					//вывод списка таблиц на экран	
	double Total_area();			//общая площадь
	void Sort();					//сортировка записей
};




