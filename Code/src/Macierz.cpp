#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <limits>

#include "Wektor.hh"
#include "ZbWektor.hh"
#include "Macierz.hh"

using namespace std;

istream & operator >> (istream & StrWe, Macierz & M)
{
	StrWe >> M._Tab[1] >> M._Tab[2] >> M._Tab[3] >> M._Tab[4];
	return StrWe;
}

ostream & operator << (ostream & StrWy, Macierz const M)
{
	cout << "macierz:" << endl; 
	StrWy << M.Tab1() << endl;
	StrWy << M.Tab2() << endl;
	StrWy << M.Tab3() << endl;
	StrWy << M.Tab4() << endl; 
	return StrWy;
}


Wektor operator * (Wektor &W, Macierz &M)
{
	//cout << M << endl;
	//cout <<"prewek" << W << endl;
	double A=W.WspA(), B=W.WspB(), W1, W2, W3, W4;
	W1=A*M.Tab1();
	W2=B*M.Tab2();
	W3=A*M.Tab3();
	W4=B*M.Tab4();
	W.S_WspA(W1+W2);
	W.S_WspB(W3+W4);
	
	//cout << "postwek" << W << endl;
	return W;
}

ZbWektor operator * (ZbWektor &P, Macierz &M)
{
	P.S_Punkt1(P.Punkt1()-P.Punkt0());
	P.S_Punkt1(P.Punkt1()*M);
	P.S_Punkt1(P.Punkt0()+P.Punkt1());
	P.S_Punkt2(P.Punkt2()-P.Punkt0());
	P.S_Punkt2(P.Punkt2()*M);
	P.S_Punkt2(P.Punkt0()+P.Punkt2());
	P.S_Punkt3(P.Punkt3()-P.Punkt0());
	P.S_Punkt3(P.Punkt3()*M);
	P.S_Punkt3(P.Punkt0()+P.Punkt3());
	P.S_Punkt4(P.Punkt4()-P.Punkt0());
	P.S_Punkt4(P.Punkt4()*M);
	P.S_Punkt4(P.Punkt0()+P.Punkt4());
	P.S_Punkt5(P.Punkt5()-P.Punkt0());
	P.S_Punkt5(P.Punkt5()*M);
	P.S_Punkt5(P.Punkt0()+P.Punkt5());
	//P.S_Punkt0(P.Punkt0()*M);
	
	return P;
}

/*Macierz operator - (Macierz &M)
{
	M._Tab[1]= -M._Tab[1];
	M._Tab[2]= -M._Tab[2];
	M._Tab[3]= -M._Tab[3];
	M._Tab[4]= -M._Tab[4];
	cout << M._Tab[1];
	return M;
}*/
	
