#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <limits>

#include "Wektor.hh"

using namespace std;

///////Wektory

Wektor operator - (Wektor &A, Wektor &B)
{
	A._Wsp1 = A._Wsp1 - B._Wsp1;
	A._Wsp2 = A._Wsp2 - B._Wsp2;
	return A;
}

Wektor Wektor::operator + (Wektor &A) 
{
	A._Wsp1 += _Wsp1;
	A._Wsp2 += _Wsp2;
	return A;
}
Wektor operator * (Wektor &W, double &A)
{
	W._Wsp1 *= A;
	W._Wsp2 *= A;
	return W;
}

ostream & operator << (ostream & StrWy, Wektor const W)
{
	StrWy << W._Wsp1 << " " << W._Wsp2; 
	return StrWy;
}

istream & operator >> (istream & StrWe, Wektor & Z1)
{
	cout << "pierwsza skladowa:";
	while(!(cin >> Z1._Wsp1))
	{
	        cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        cout << "niewlasciwa dana. sprobuj ponownie: ";
	}
	cout << "druga skladowa:";
	while(!(cin >> Z1._Wsp2))
	{
	        cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        cout << "niewlasciwa dana. sprobuj ponownie: ";
	}
	return StrWe;
}





