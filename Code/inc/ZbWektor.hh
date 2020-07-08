#ifndef ZbWektor_HH
#define ZbWektor_HH

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

#include "Wektor.hh"
#include "lacze_do_gnuplota.hh"

/*!
 * \file  ZbWektor.hh
 *  
 *  Plik zawiera definicję klasy zbierającej Wektory
 *  w obiekt
 */

/*!
 * \brief Moduł zaiwera klase ZbWektor laczaca wektory w obiekty
 *
 * Niniejsza przestrzeń nazw stanowi moduł logiczny zawiera
 * funkcje i metody pozawalajace na przemieszczanie obiektu 
 * i pomocniczze do wykrywania kolizji
 */

using namespace std;

class ZbWektor 
{
  
	protected:

		Wektor _Punkt[6];  //inicjacja prywatnej tablicy wektorow ZbWektora
	  
	public:
		
		ZbWektor (double A1, double A2, double B1, double B2, double C1, double C2, double D1, double D2, double E1, double E2, double F1, double F2); // konstruktor zbioru z wartosciami wektorow
		ZbWektor (); // konstruktor zbioru wektorow baz wartosci

		// gettery 
		Wektor Punkt1() const {return _Punkt[1];}// const getter z tablicy Wektorow
		Wektor Punkt2() const {return _Punkt[2];}// const getter z tablicy Wektorow
		Wektor Punkt3() const {return _Punkt[3];}// const getter z tablicy Wektorow
		Wektor Punkt4() const {return _Punkt[4];}// const getter z tablicy Wektorow
		Wektor Punkt5() const {return _Punkt[5];}// const getter z tablicy Wektorow
		Wektor Punkt0() const {return _Punkt[0];}// const getter z tablicy Wektorow
		
		// gettery z referencja
		Wektor & Punkt1() {return _Punkt[1];}//getter z referencja z tablicy Wektorow
		Wektor & Punkt2() {return _Punkt[2];}//getter z referencja z tablicy Wektorow
		Wektor & Punkt3() {return _Punkt[3];}//getter z referencja z tablicy Wektorow
		Wektor & Punkt4() {return _Punkt[4];}//getter z referencja z tablicy Wektorow
		Wektor & Punkt5() {return _Punkt[5];}//getter z referencja z tablicy Wektorow
		Wektor & Punkt0() {return _Punkt[0];}//getter z referencja z tablicy Wektorow

		// settery
		void S_Punkt1(Wektor P1) { _Punkt[1]=P1; }//setter z tablicy Wektorow
		void S_Punkt2(Wektor P2) { _Punkt[2]=P2; }//setter z tablicy Wektorow
		void S_Punkt3(Wektor P3) { _Punkt[3]=P3; }//setter z tablicy Wektorow
		void S_Punkt4(Wektor P4) { _Punkt[4]=P4; }//setter z tablicy Wektorow
		void S_Punkt5(Wektor P5) { _Punkt[5]=P5; }//setter z tablicy Wektorow
		void S_Punkt0(Wektor P0) { _Punkt[0]=P0; }//setter z tablicy Wektorow
	
		friend ostream & operator << (ostream & StrWy, ZbWektor const W);
		/*!
		* \zbiera wektory z ZbWektora 
		* 
		* wyswietla je na standardowym wyjsciu
		*/
	
		void Przekatna ();
		/*!
		* \zbiera wektory z ZbWektora i oblicza odleglosc miedzy nimi
		* 
		* wyswietla dane odleglosci na standardowym wyjsciu
		*/
	
		friend ZbWektor operator + (ZbWektor & A, Wektor & B);
		/*!
		* \zbiera wektory ZbWektora i wektor 
		* \dodaje wektor do kazdego wektora ZbWektora 
		* 
		* zwraca ZbWektor o zmienionych wektorach
		*/
	
};

	void Wyswietl(ZbWektor & R);
	/*!
	* \Wyswietla pozycje robota w programie gnuplot
	*
	* 
	*/

	bool Czy_przecina1 (Wektor A, Wektor B);
	/*!
	* \Sprawdza, czy robor nie narusza wysokości przeszkody
	*
	* 
	*/

	bool Czy_przecina2 (Wektor A, Wektor B);
	/*!
	* \Sprawdza, czy robor nie narusza szerokości przeszkody
	*
	* 
	*/

#endif
