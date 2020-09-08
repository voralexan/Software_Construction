#pragma once

#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct TNote             // ������ � ������
{
	string str;		//������ � ���� ������	
	double area;	//������� ������
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
	vector <TNote*> List_curves;	//������, � ������� �������� ������
protected:
	unsigned int length;         // ���������� ������� � �������
public:
	Figures();
	~Figures();
	void Insert();					// ���������� ����� ������
	void Print();					//����� ������ ������ �� �����	
	double Total_area();			//����� �������
	void Sort();					//���������� �������
};




