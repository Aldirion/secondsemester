#include "menu.h"
#include "Struct.h"
#include <iostream>
using namespace std;


extern bool exit_m;
menu::menu()
{
	exit_m = false;
	while (!exit_m)
	{
		system("cls");
		cout << "Please choise the lab\n";
		cout << "1. Dynamic array of structures;\n";
		cout << "2. Classes in C++;(not availible)\n";
		cout << "3. Overloading operations, Friendly functions;(not availible)\n";
		cout << "4. Inheritance;(not availible)\n";
		cout << "5. Templates;(not availible)\n";
		cout << "6. Exceptions;(not availible)\n";
		cout << "0. EXIT;";
		cout << "\n\n\n>>> ";
		menu::choose(cin);
	}
}

void menu::choose(istream& cin)
{
	cin >> chs;
	switch (chs)
	{
	case 0:
	{
		exit_m = true;
		break;
	}
	case 1:
	{
		system("cls");
		lab_1_20_start();
		system("pause");
		break;
	}
	}
}
menu::~menu()
{
}
