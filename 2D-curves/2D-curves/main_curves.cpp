#include <iostream>
#include <string>
#include <cstdlib>
#include<locale>
#include "Figures.h"

using namespace std;

int main()
{
	int n;
	Figures f;
	start:
		try
		{
			cout << endl;
			cout << "Choose the action:" << endl;
			cout << "1 - add the curve" << endl;
			cout << "2 - show curves" << endl;
			cout << "3 - sort curves in the list by area" << endl;
			cout << "4 - count total area" << endl;
			cin >> n;
			if (n == 1)
			{
				f.Insert();
				goto start;
			}
			else if (n == 2)
			{
				f.Print();
				goto start;
			}
			else if (n == 3)
			{
				f.Sort();
				f.Print();
				goto start;
			}
			else if (n == 4)
			{
				cout << "Total area of figures = " << f.Total_area() << endl;
				goto start;
			}
			else
			{
				cout << "Incorrect data " << endl;
				goto start;
			}
		}
		catch (const char* s)
		{
			cout << s << endl;
			goto start;
		}
}