#include <iostream>
#include "Read_File.h"
using namespace std;

int main()
{
	Read_File w1("data.txt");

	w1.show();
	w1.Wypelnij_macierze();
	w1.Gauss();
	system("pause");
	return 0;
}