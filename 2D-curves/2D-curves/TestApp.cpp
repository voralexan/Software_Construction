#include <iostream>
#include <string>
#include <cstdlib>
#include<locale>

#include "Figures.h"

using namespace std;

int main()
{
	Figures figures;
	int cmd = 1;
	while (cmd != 0) {
		cout << endl;
		cout << "Choose the action:" << endl;
		cout << "0 - Exit" << endl;
		cout << "1 - Add new curve" << endl;
		cout << "2 - Generate random curves" << endl;
		cout << "3 - Show the list of curves" << endl;
		cout << "4 - Sort curves in the list by area" << endl;
		cout << "5 - Count total area" << endl;

		cin >> cmd;
		switch (cmd)
		{

		default:
			cout << "Incorrect data " << endl;
			break;

		case 0:
			break;

		case 1:
			figures.insert();
			break;

		case 2:
			cout << "Enter count: " << endl;
			int count;
			cin >> count;
			figures.generateRandomFigures(count);
			break;

		case 3:
			figures.print();
			break;
		case 4:
			figures.sortByArea();
			figures.print();
			break;
		case 5:
			cout << "Total area of figures = " << figures.getTotalArea() << endl;
			break;

		}
	}
	system("pause");
	return 0;
}