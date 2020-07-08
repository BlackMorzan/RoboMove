#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

#include "Wektor.hh"
#include "ZbWektor.hh"

/*!
 * \file  Macierz.hh
 *  
 *  Plik zawiera definicję klasy umożliwiającej 
 *  obrót robota
 */

/*!
 * \brief Moduł działań na Macierzach
 *
 * Niniejsza przestrzeń nazw stanowi moduł logiczny zawierający
 * metody umożliwiające obracanie robota
 */

using namespace std;

class Macierz 
{
	private:

		double _Tab[5]; //inicjacja prywatnej tablicy macierzy
	  
	public:
	  
		Macierz (double A=0, double B=0, double C=0, double D=0) // kostruktor macierzy z wartosciami
		{ _Tab[1]=A; _Tab[2]=B; _Tab[3]=C; _Tab[4]=D; }
	  
		double Tab1() const {return _Tab[1];}//staly getter z tablicy double
		double Tab2() const {return _Tab[2];}//staly getter z tablicy double
		double Tab3() const {return _Tab[3];}//staly getter z tablicy double
		double Tab4() const {return _Tab[4];}//staly getter z tablicy double

		double & Tab1() {return _Tab[1];}// getter z referencja z tablicy double
		double & Tab2() {return _Tab[2];}// getter z referencja z tablicy double
		double & Tab3() {return _Tab[3];}// getter z referencja z tablicy double
		double & Tab4() {return _Tab[4];}// getter z referencja z tablicy double

		void S_Tab1(double W1) { _Tab[1]=W1; }// setter z tablicy double
		void S_Tab2(double W2) { _Tab[2]=W2; }// setter z tablicy double
		void S_Tab3(double W3) { _Tab[3]=W3; }// setter z tablicy double
		void S_Tab4(double W4) { _Tab[4]=W4; }// setter z tablicy double
	  
		friend istream & operator >> (istream & StrWe, Macierz & W);
		/*!
		* \zbiera dane ze strumienia wejsciowego
		* 
		* nadaje macierzy nowe wartosci
		*/

		friend ostream & operator << (ostream & StrWy, Macierz const W);
		/*!
		* \zbiera wartosci macierza 
		* 
		* wyswietla zebrane wartosci
		*/
	  
		friend ZbWektor operator * (ZbWektor &P, Macierz &M);
		/*!
		* \zbiera wektory prostokata i wartosci macierzy
		* \wykonuje mnozenie wektorowe na kazdym wektorze
		* 
		* zwraca obrocony prostokat 
		*/

		friend Wektor operator * (Wektor &W, Macierz &M);
		/*!
		* \zbiera wektor i macierz 
		* \mnozy wektorowo wektori macierz
		* 
		* zwraca obrocony wektor
		*/

		//friend Macierz operator - (Macierz &M);
		/*!
		* \zbiera macierz 
		* 
		* zwraca przeciwna macierz
		*/

	
};

#endif
