#include <iostream>
#include <string>
#include "Read_File.h"
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

Read_File::Read_File(string FilePath)
{

	ifstream source;                    // build a read-Stream

	source.open("data.txt", ios_base::in);  // open data
	system("pause");
	if (!source) {                     // if it does not work
		cerr << "Can't open Data!\n";
	}
	else {

		//cout << "OK" << endl;
		char c;

		for (int i = 0; i < 4; i++) {

			for (int j = 0; j < 4; j++) {
				source.get(c);
				//system("pause");
				string x = "";
				while (c != ' ' && !source.eof()) {
					x = x + c;
					//cout <<"Znaleziona cyfra to: "<< c << endl;
					//system("pause");
					source.get(c);
				}
				//cout << "Ciıg znaków to: "<< x << endl;
				tab[i][j] = atof(x.c_str());
				//cout << tab[i][j] << endl;
				if (j == 3 && i == 3)
				{
					return;
				}


			}
			source.get(c);
			if (source.eof())
			{
				return;
			}

		}
	}
	T = tab[0][1];
	q = tab[0][2];
	alfa = tab[0][3];
	//system("pause");
}

Read_File::~Read_File()
{
	cout << endl << "To ja, destruktor sie nazywam";
	cout << " kasuje obiekty, slowa przepraszam nie uzywam";
}
void Read_File::show()
{
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; j++) {
			cout << tab[i][j] << "   ";

		}
		cout << endl;
	}


}

void Read_File::Wypelnij_macierze() {

	float S = tab[1][3]; //tab[][];
	float K = tab[1][2];
	float L1 = tab[2][1];
	float L2 = tab[3][1];
	float ALFA = tab[0][3];
	float q = tab[0][2];
	float T_Nieskonczonosc = tab[0][1];

	Macierz_duza[0][0] = ((S *K) / L1);
	Macierz_duza[0][1] = -((S *K) / L1);
	Macierz_duza[0][2] = 0;
	Macierz_duza[1][0] = -((S*K) / L1);
	Macierz_duza[1][1] = ((S*K)*((1 / L1) + (1 / L2)));
	Macierz_duza[1][2] = -((S*K) / L2);
	Macierz_duza[2][0] = 0;
	Macierz_duza[2][1] = -((S*K) / L2);
	Macierz_duza[2][2] = (((S*K) / L2) + (ALFA * S));

	Macierz_mala[0] = (q * S);
	Macierz_mala[1] = (0);
	Macierz_mala[2] = -(ALFA * T_Nieskonczonosc * S);
	cout << endl;
	/*cout << Macierz_mala[0];
	cout << endl;
	cout << Macierz_mala[1];
	cout << endl;
	cout << Macierz_mala[2];
	cout << endl;

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {
			cout << Macierz_duza[i][j] << "   ";

		}
		cout << endl;
	}*/

}

void Read_File::Gauss()
{

	float divisor;
	int n = 3;

	// eliminacja wspó³czynników

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			divisor = Macierz_duza[j][i] / Macierz_duza[i][i];
			for (int k = 0; k < n; k++) {
				Macierz_duza[j][k] -= divisor * Macierz_duza[i][k];
			}

			Macierz_mala[j] -= divisor * Macierz_mala[i];
		}

	}
	//wywietlanie
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << (Macierz_duza[i][j]);
		}
		cout << (Macierz_mala[i]);
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << "T" << (i + 1) << " = ";
		cout << -(Macierz_mala[i] / Macierz_duza[i][i]);
		cout << endl;
	}


}