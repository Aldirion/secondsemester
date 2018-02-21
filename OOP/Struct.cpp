#define _CRT_SECURE_NO_WARNINGS
#include "Struct.h"
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

void lab_1_20_start()
{
	fill();
	A:
	char filename[40];
	cout << "Please enter the filename:\n\n\n>>> ";
	cin >> filename;
	fstream fin(filename, ios::in);
	if (fin)
	{
		system("cls");
		char c[2];
		fin.getline(c, 2);
		Product* product = new Product[atoi(c)];
		struct_input(product, atoi(c), fin);
		struct_sort(product, atoi(c));
		struct_output(product, atoi(c));
	}
	else
	{
		cout << "Something wrong, try again";
		goto A;
	}
}

void fill()
{
	cout.fill('#');
}

void struct_input(Product *p, int count, fstream& fin)
{
	int i = 0;
	while (!fin.eof() && i<count)
	{
		char* line = new char[80];
		fin.getline(line, 79);
		strtok(line, "|");
		(p + i)->date = line;
		line = strtok(NULL, "|");
		(p + i)->type = line;
		line = strtok(NULL, "|");
		(p + i)->name = line;
		line = strtok(NULL, "|");
		(p + i)->count = atoi(line);
		cout << setw(10) << (p + i)->date << setw(10) << (p + i)->type << setw(10) << (p + i)->name << setw(10) << (p + i)->count << "\n";
		i++;
	}
}

void struct_sort(Product *p, int count)
{
	Product temp;
	int x = 0, y = 0;
	bool exit = false;
	while (!exit)
	{
		exit = true;
		for (int i = 0; i < count - 1; i++)
		{
			if ((x = (p + i)->count) < (y = (p + i + 1)->count))
			{

				{
					temp.date = (p + i)->date;
					temp.type = (p + i)->type;
					temp.name = (p + i)->name;
					temp.count = (p + i)->count;
				}
				{
					(p + i)->date = (p + i + 1)->date;
					(p + i)->type = (p + i + 1)->type;
					(p + i)->name = (p + i + 1)->name;
					(p + i)->count = (p + i + 1)->count;
				}
				{
					(p + i + 1)->date = temp.date;
					(p + i + 1)->type = temp.type;
					(p + i + 1)->name = temp.name;
					(p + i + 1)->count = temp.count;
				}
				exit = false;
			}
		}
	}
}

void struct_output(Product *p, int c)
{
	fstream fout("output.txt", ios::out), o_date("o_date.txt", ios::out), o_type("o_type.txt", ios::out), o_name("o_name.txt", ios::out), o_count("o_count.txt", ios::out);
	fout << setw(10) << "date" << setw(10) << "type" << setw(10) << "name" << setw(10) << "count\n";
	cout << "\n\n\n";
	for (int i = 0; i < c; i++)
	{
		//вывод на экран
		cout << setw(10) << (p + i)->date << setw(10) << (p + i)->type << setw(10) << (p + i)->name << setw(10) << (p + i)->count << "\n";
		//вывод всей сводки в общий файл
		fout << setw(10) << (p + i)->date << setw(10) << (p + i)->type << setw(10) << (p + i)->name << setw(10) << (p + i)->count << "\n";
		//вывод сводки в соответствующие файлы
		o_date << i + 1 << ". " << (p + i)->date << "\n";
		o_type << i + 1 << ". " << (p + i)->type << "\n";
		o_name << i + 1 << ". " << (p + i)->name << "\n";
		o_count << i + 1 << ". " << (p + i)->count << "\n";
	}
}