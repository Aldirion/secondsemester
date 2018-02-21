#pragma once
#include <iostream>
class menu
{
private:
	int chs;
public:
	menu();

	void choose(std::istream& cin);
	
	~menu();
};

