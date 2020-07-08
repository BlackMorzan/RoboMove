#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <limits>

#include "Wektor.hh"
#include "ZbWektor.hh"
#include "lacze_do_gnuplota.hh"

using namespace std;

ZbWektor::ZbWektor(double A1, double A2, double B1, double B2, double C1, double C2, double D1, double D2, double E1, double E2, double F1, double F2)
{
	Wektor A(A1,A2), B(B1,B2), C(C1,C2), D(D1,D2), E(E1,E2), F(F1,F2);
	_Punkt[1]=A;
	_Punkt[2]=B;
	_Punkt[3]=C;
	_Punkt[4]=D;
	_Punkt[5]=E;
	_Punkt[0]=F;
}


ZbWektor::ZbWektor()
{
	Wektor A(-1,-1), B(1,-1), C(1,1), D(0,2), E(-1,1), F(0,0);
	_Punkt[1]=A;
	_Punkt[2]=B;
	_Punkt[3]=C;
	_Punkt[4]=D;
	_Punkt[5]=E;
	_Punkt[0]=F;
}


ostream & operator << (ostream & StrWy, ZbWektor const W)
{
	StrWy << W._Punkt[1] << endl;
	StrWy << W._Punkt[2] << endl;
	StrWy << W._Punkt[3] << endl;
	StrWy << W._Punkt[4] << endl;
	StrWy << W._Punkt[0] << endl;
	StrWy << W._Punkt[4] << endl; 
	StrWy << W._Punkt[5] << endl; 	
	StrWy << W._Punkt[1] << endl; 
	return StrWy;
}

ZbWektor operator + (ZbWektor & A, Wektor & B)
{
	A._Punkt[1]=B + A._Punkt[1];
	A._Punkt[2]=B + A._Punkt[2];
	A._Punkt[3]=B + A._Punkt[3];
	A._Punkt[4]=B + A._Punkt[4];
	A._Punkt[5]=B + A._Punkt[5];
	A._Punkt[0]=B + A._Punkt[0];
	return A;
}

void Wyswietl(ZbWektor & R)
{
	PzG::LaczeDoGNUPlota  Lacze;
	std::fstream plik;

	plik.open( "Mira.dat",  std::ios::out );
	
	if( plik.good() == true )
		plik << R;

	plik.close();			

	Lacze.DodajNazwePliku("Mira.dat",PzG::RR_Ciagly,2);
	Lacze.DodajNazwePliku("Mira.dat",PzG::RR_Punktowy,2);
	Lacze.ZmienTrybRys(PzG::TR_2D);
	Lacze.UstawZakresX(-10, 10);
	Lacze.UstawZakresY(-10, 10);
	Lacze.Rysuj();
}


bool Czy_przecina1 (Wektor A, Wektor B)
{
	if ((A.WspA()+2)>=B.WspA() && (A.WspB()+2)>=B.WspB())
		return true;
	return false;	
}

bool Czy_przecina2 (Wektor A, Wektor B)
{
	if ((A.WspA()-2)<=B.WspA() && (A.WspB()-2)<=B.WspB())
		return true;
	return false;	
}

