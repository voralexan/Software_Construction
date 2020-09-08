#include <iostream>
#include <string>
#include <cstdlib>
#include<locale>

#include "Figures.h"

using namespace std;

int main()
{
	Figures f;
	int cmd=1;
	while (cmd != 0) {
		cout << endl;
		cout << "Choose the action:" << endl;
		cout << "0 - exit" << endl;
		cout << "1 - add the curve" << endl;
		cout << "2 - show curves" << endl;
		cout << "3 - sort curves in the list by area" << endl;
		cout << "4 - count total area" << endl;
		cout << "5 - generate random curves" << endl;
		cin >> cmd;
		switch (cmd)
		{
		default:
			cout << "Incorrect data " << endl;
			break;
		case 0:
			break;
		case 1:
			f.Insert();
			break;

		case 2:
			f.Print();
			break;
		case 3:
			f.Sort();
			f.Print();
			break;
		case 4:
			cout << "Total area of figures = " << f.Total_area() << endl;
			break;
		case 5:
			cout << "Enter count: " << endl;
			int count;
			cin >> count;
			f.GenerateRandomFigures(count);
			break;
		}
	}
	system("pause");
	return 0;
}