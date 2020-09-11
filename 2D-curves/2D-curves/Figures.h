#pragma once

#include <string>
#include <iostream>
#include <vector>

struct TNote             // ������ � ������
{
	std::string str;		//������ � ���� ������	
	double area;			//������� ������
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
	std::vector <TNote*> List_curves;	//������, � ������� �������� ������

public:
	Figures() {
	};
	~Figures() {

		for (auto i : List_curves)
		{
				delete i;
		}
	};
	void Insert();					// ���������� ����� ������
	void GenerateRandomFigures(int amount);
	void Print();					//����� ������ ������ �� �����	
	double Total_area();			//����� �������
	void Sort();					//���������� �������
};




