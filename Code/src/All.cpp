#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <unistd.h>

#include "Wektor.hh"
#include "lacze_do_gnuplota.hh"
#include "ZbWektor.hh"
#include "Macierz.hh"
#include "Robot.hh"
#include "Sciezka.hh"
#include "All.hh"

using namespace std;

void All()
{
	
	Macierz Macie(1,1,1,1);
	Wektor Wek(0,0);

	Robot Mira[4];
	
	Robot Mira1;
	Robot Mira2(4,0/*A*/,6,0/*B*/,6,2/*C*/,5,3/*D*/,4,2/*E*/,5,1/*F*/,0);
	Robot Mira3(-6,2/*A*/,-4,2/*B*/,-4,4/*C*/,-5,5/*D*/,-6,4/*E*/,-5,3/*F*/,0);	

	Mira[1]=Mira1;
	Mira[2]=Mira2;
	Mira[3]=Mira3;

	ZbWektor Przeszkoda1(-2,4/*A*/,2,4/*B*/,2,8/*C*/,-2,8/*D*/,-2,4/*E*/,-2,4/*F*/),
	Przeszkoda2(-8,-8/*A*/,-4,-8/*B*/,-4,-2/*C*/,-8,-2/*D*/,-8,-8/*E*/,-8,-8/*F*/);
	Sciezka Droga;
	double time=5000, y=5000;
	int i, k, WybRobot=1;
	double x, o;

	PzG::LaczeDoGNUPlota  Lacze;
	char h;
	std::fstream plik;
	
	
	Lacze.DodajNazwePliku("Mira.dat",PzG::RR_Ciagly,2);
	//Lacze.DodajNazwePliku("Mira2.dat",PzG::RR_Ciagly,2);
	//Lacze.DodajNazwePliku("Mira3.dat",PzG::RR_Ciagly,2);
	Lacze.DodajNazwePliku("Przeszkoda1.dat",PzG::RR_Ciagly,2);
	Lacze.DodajNazwePliku("Sciezka.dat",PzG::RR_Ciagly,2);
	Lacze.DodajNazwePliku("Sciezka.dat",PzG::RR_Punktowy,1);
	Lacze.ZmienTrybRys(PzG::TR_2D);
	Lacze.UstawZakresX(-10, 10);
	Lacze.UstawZakresY(-10, 10);
	
	Droga.S_TabWek(Wek);
	Menu();
	
	plik.open( "Mira.dat",  std::ios::out );
	if( plik.good() == true )
		for (k=1;k<=3;k++)
			plik << Mira[k] << endl;
	plik.close();
	
	plik.open( "Przeszkoda1.dat",  std::ios::out );
	if( plik.good() == true )
		plik << Przeszkoda1 << endl << Przeszkoda2;
	plik.close();		

	plik.open( "Sciezka.dat",  std::ios::out );
	if( plik.good() == true )
		plik.clear();
	plik.close();		

	
	
	///////////////////////////////GLOWNA PETLA PROGRAMU////////////////////////////////////
	
	
	while (true)
	{
		cout << endl;
	
		plik.open( "Sciezka.dat",  std::ios::app );
		if( plik.good() == true )
			plik << Mira[WybRobot].Punkt0() << endl;
		plik.close();		

		Lacze.Rysuj();
	
		//cout << _IloscNow << endl;
		//cout << _IloscAll << endl;

		cout << "Twoj wybor (w - wyswietl menu)>";
		cin >> h;
		
	
			switch (h)
			{
			case 's':
				cout << "Wybierz robota:" ;
				while (true)
				{
					WybRobot=Read();
					if (WybRobot>0 && WybRobot<4)
						break;
				}
				plik.open( "Sciezka.dat",  std::ios::app );
				if( plik.good() == true )
					plik << endl;
				plik.close();		
				
				break;
				
			case 'l':
				cout << "obrot robota" << endl;
				Macie=MakeMacierz(Macie, Mira[WybRobot]);
				Mira[WybRobot]*Macie;
				break;
				
			case 'o':
				cout << "Podaj wartosc kata obrotu robota w stopniach." << endl;
				cout << "Kat obrotu: ";
				
				o=Read();
				o*=10;
				for (i=1;i<abs(o);i++)
				{
					Macie=Obrot(Macie, Mira[WybRobot], o);
					Mira[WybRobot]*Macie;
					
					plik.open( "Mira.dat",  std::ios::out );
					if( plik.good() == true )
						for (k=1;k<4;k++)
							plik << Mira[k] << endl << endl;
					plik.close();
					
					Lacze.Rysuj();
					
					usleep(time);
				}
				break;
			
			case 'r':
				Przesun(Mira[WybRobot]);
				Droga.S_TabWek(Mira[WybRobot].Punkt0());
				break;

			case 'j':
				cout << "Podaj dlugosc drogi ruchu robota na wprost." << endl;
				cout << "Dlugosc drogi: ";
				x=Read();
				x*=100;
				for (i=1;i<=abs(x);i++)
				{
					usleep(time);
					if (Ruch(Mira, x, Przeszkoda1, Przeszkoda2, WybRobot))
						break;
					plik.open( "Mira.dat",  std::ios::out );
					if( plik.good() == true )
						for (k=1;k<4;k++)
							plik << Mira[k] << endl << endl;
					plik.close();	
					Lacze.Rysuj(); 
					//cout << "jedzie";
				}
				Droga.S_TabWek(Mira[WybRobot].Punkt0());
				break;
			
			case 'z':
				cout << "zmiana opoznienie: ";
				time=Read();
				if (time<1)
					cout << "UWAGA!!!" << endl << "opoznienie mniejsze niz \"1\" moze powodowac bledy" << endl;
				time*=y;
				break;
			
			case 't':
				cout << "Aktualny całkowity wektor translacji";
				cout << "wzgledem poczatkowego polozenia sceny: " << endl;
				//Mira.Przekatna();
				cout << "Wpisz wspolrzedne wektora lokalnej translacji rysunku sceny.";
				cout << "Podaj wartosci: x y > " << endl;
				break;
			
			case 'w': 
				Menu();
				break;
			
			case 'p':  
				cout << "Przywrocone zostalo poczatkowe ustawienie sceny." << endl;
				//jakas funkcja ()
				//cout << Mira;
				break;
			
			case 'k':
				cout << "konczenie pracy programu" << endl;
				//cout << _IloscNow << endl;
				//cout << _IloscAll << endl;
				return;
			
			default:
				cout << "nieznane polecenie" << endl;
		
		}
	}
	cout << "cos poszlo nie tak";
	return;
}

double Read()
{
	double liczba;
	while(!(cin >> liczba))
	{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "To nie liczba. sprobuj ponownie: ";
	}
	return liczba;
}
