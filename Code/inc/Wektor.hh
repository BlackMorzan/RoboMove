#ifndef WEKTOR_HH
#define WEKTOR_HH


#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

/*!
 * \file  Wektor.hh
 *  
 *  Plik zawiera definicję klasy Wektor i podstawowych
 *  operacji na nim
 */

/*!
 * \brief Moduł Wektora i dzialan na nim
 *
 * Niniejsza przestrzeń nazw stanowi moduł logiczny zawierający
 * opreacje wczytywania, zapisywania, dodawania i mnozenia wektorow
 */


static int _IloscAll;
static int _IloscNow;

class Wektor 
{
		
		double _Wsp1, _Wsp2; //inicjacja prywatnych zmiennych wektora

	public:	

		double WspA() const {return _Wsp1;} //dostep do 1-szej wsporzednej
		double WspB() const {return _Wsp2;} //dostep do 2-giej wsporzednej
	
		void S_WspA(double A) { _Wsp1=A; } //nadpisanie 1-szej wsporzednej
		void S_WspB(double B) { _Wsp2=B; } //nadpisanie 2-giej wsporzednej


		Wektor(double a, double b) { _Wsp1=a;  _Wsp2=b; _IloscNow++; _IloscAll++; }//kostruktor dla wektora z wartosciami a i b

		Wektor() { _Wsp1=0;  _Wsp2=0; _IloscNow++; _IloscAll++;}//kostruktor dla wektora z bez wartosci

		Wektor(const Wektor &A) { _Wsp1=A._Wsp1; _Wsp2=A._Wsp2; _IloscNow++; _IloscAll++; }//konstruktor kopiujacy wektora

		~Wektor() { _IloscNow--; }// dekonstruktor wektora


		friend istream & operator >> (istream & StrWe, Wektor & Z1);
		/*!
		* \zbiera dane ze strumienia wejsciowego
		* 
		* nadaje wektorowi nowe wartosci
		*/

		friend ostream & operator << (ostream & StrWy, Wektor const W);
		/*!
		* \zbiera wartosci wektora 
		* 
		* wyswietla zebrane wartosci
		*/
	
		Wektor operator + (Wektor &A);
		/*!
		* \zbiera wartosci 2 wektorow i dodaje je
		* 
		* zwraca wektor po dodaniu
		*/

		friend Wektor operator - (Wektor &A, Wektor &B);
		/*!
		* \zbiera wartosci 2 wektorow i odejmuje je
		* 
		* zwraca wektor po dodaniu
		*/

		friend Wektor operator * (Wektor &W, double &A);
		/*!
		* \zbiera wartosci wektora i odleglosci 
		* \ i mnozy je
		* 
		* zwraca wektor po dodaniu
		*/
		
};



#endif

