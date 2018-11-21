#include <iostream>

using namespace std;

class Read_File
{

	float tab[4][4];
	float alfa, T, q;
	float Macierz_duza[3][3];
	float Macierz_mala[3];


public:

	Read_File(string);
	~Read_File();
	void show();
	void Wypelnij_macierze();
	void Gauss();


};