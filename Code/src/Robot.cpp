#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <limits>

#include "Wektor.hh"
#include "ZbWektor.hh"
#include "Macierz.hh"
#include "Robot.hh"
#include "lacze_do_gnuplota.hh"

using namespace std;
std::fstream plik;

Robot::Robot(double A1, double A2, double B1, double B2, double C1, double C2, double D1, double D2, double E1, double E2, double F1, double F2, double S)
:ZbWektor (A1, A2, B1, B2, C1, C2, D1, D2, E1, E2, F1, F2)
{
	_RadObr=S;	
}

Robot::Robot()
:ZbWektor ()
{
	_RadObr=0;
}

Macierz & MakeMacierz(Macierz & M, Robot & R)
{
	
	double kat;
	
	cout << "Podaj wartosc kata obrotu robota w stopniach." << endl;
	cout << "Kat obrotu: ";
	
	while(!(cin >> kat))
	{
	        cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        cout << "niewlasciwa dana. sprobuj ponownie: ";
	}
	
	R.S_RadObr(kat*M_PI/180);

	M.S_Tab1(cos(R.G_RadObr()));
	M.S_Tab2(-sin(R.G_RadObr()));
	M.S_Tab3(sin(R.G_RadObr()));
	M.S_Tab4(cos(R.G_RadObr()));
	return M;
}


Macierz & Obrot(Macierz & M, Robot & R, double x)
{	
	R.S_RadObr(M_PI/180*0.1);
	
	if (x<0)
		R.S_RadObr(-R.G_RadObr());

	M.S_Tab1(cos(R.G_RadObr()));
	M.S_Tab2(-sin(R.G_RadObr()));
	M.S_Tab3(sin(R.G_RadObr()));
	M.S_Tab4(cos(R.G_RadObr()));
	return M;
}


void Przesun(Robot & R)
{
	double A;
	Wektor Spec;	
	Spec=R.Punkt4();
	cout << "Podaj dlugosc drogi ruchu robota na wprost." << endl;
	cout << "Dlugosc drogi: ";
	cin >> A;
	
	Spec=Spec-R.Punkt0();
	A=A/2;
	Spec=Spec*A;
	
	
	R.S_Punkt0(Spec+R.Punkt0());
	R.S_Punkt1(Spec+R.Punkt1());
	R.S_Punkt2(Spec+R.Punkt2());
	R.S_Punkt3(Spec+R.Punkt3());
	R.S_Punkt4(Spec+R.Punkt4());
	R.S_Punkt5(Spec+R.Punkt5());
}

bool Ruch(Robot R[], double a, ZbWektor A, ZbWektor B, int WybRobo)
{
	double x=0.005;
	
	if (a<0)
		x=-x;
	Wektor Spec, Poprzedni;	
	Spec=R[WybRobo].Punkt4();
	
	Spec=Spec-R[WybRobo].Punkt0();
	Spec=Spec*x;

	Poprzedni=R[WybRobo].Punkt0();
	Poprzedni-Spec;
	R[WybRobo].S_Punkt0(Spec+R[WybRobo].Punkt0());
	if ( Kolizja(R[WybRobo], A) || Kolizja(R[WybRobo], B) )
	{
		R[WybRobo].S_Punkt0(Poprzedni);
		cout << "niebezpieczenstwo kolizji z przeszkoda" << endl;
		return true;
	}
	
	
	if (KolizjaRobo(R, WybRobo)>1)
	{	
		R[WybRobo].S_Punkt0(Poprzedni);
		cout << "niebezpieczenstwo kolizji z robotem" << endl;
		return true;
	}
	R[WybRobo].S_Punkt1(Spec+R[WybRobo].Punkt1());
	R[WybRobo].S_Punkt2(Spec+R[WybRobo].Punkt2());
	R[WybRobo].S_Punkt3(Spec+R[WybRobo].Punkt3());
	R[WybRobo].S_Punkt4(Spec+R[WybRobo].Punkt4());
	R[WybRobo].S_Punkt5(Spec+R[WybRobo].Punkt5());
	
	return false;

}

bool Kolizja(Robot R, ZbWektor A)
{
	if(Czy_przecina1 (R.Punkt0(), A.Punkt1()) && Czy_przecina2 (R.Punkt0(), A.Punkt3()))
		return true;
	return false;
}

int KolizjaRobo(Robot R[], int WybRobo)
{
	int i, q=0;
	for (i=1;i<=3;i++)
		if ( sqrt ( OdlegloscRobo1(R[WybRobo].Punkt0(), R[i].Punkt0()) + OdlegloscRobo2(R[WybRobo].Punkt0(), R[i].Punkt0()) ) < 4 )
			q++;
	return q;
}

double OdlegloscRobo1(Wektor A, Wektor B)
{
	return pow(B.WspA()-A.WspA(), 2);
}

double OdlegloscRobo2(Wektor A, Wektor B)
{
	return pow(B.WspB()-A.WspB(), 2);
}




