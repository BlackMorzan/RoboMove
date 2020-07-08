#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <limits>
#include <vector>

#include "Wektor.hh"
#include "Sciezka.hh"

using namespace std;

ostream & operator << (ostream & StrWy, Sciezka S)
{
	for (const Wektor & W : S._TabWek)
		StrWy << W << endl; 
	return StrWy;
}

void Menu()
{
	cout << "z - zmiana szybkosci ruchu robota" << endl;
	cout << "o - obrot robota (dokladnosc do 0.1) " << endl;
	cout << "j - jazda na wprost (dokladnosc do 0.01) " << endl;
	cout << "t - zadaj translacje rysunku" << endl;
	cout << "p - powrot do pierwotnego ustawienia rysunku" << endl;
	cout << "w - wyswietl ponownie menu" << endl;
	cout << "k - zakoncz dzialanie programu" << endl;
}
