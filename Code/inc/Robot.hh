#ifndef ROBOT_HH
#define ROBOT_HH

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <limits>

#include "Wektor.hh"
#include "ZbWektor.hh"
#include "Macierz.hh"
#include "lacze_do_gnuplota.hh"

/*!
 * \file  Robot.hh
 *  
 *  Plik zawiera definicję klasy pochodnej ZbWektor
 *  umożiwiającej budowę robota i operacji na nim
 */

/*!
 * \brief Moduł zawiera klasę Robot i większość operacji na nim
 *
 * Niniejsza przestrzeń nazw stanowi moduł logiczny zawierający
 * funkcę poruszania, obrotu i kolizji 
 */

using namespace std;

class Robot : public ZbWektor
{
	protected:
	
		double _RadObr;
	
	public:
	
		Robot(double A1, double A2, double B1, double B2, double C1, double C2, double D1, double D2, double E1, double E2, double F1, double F2, double S);// kostruktor robota z wartosciami

		Robot();// konstruktor robota bez wartosci

		double & G_RadObr() {return _RadObr;}// getterz referencja wartosci obrotu
		
		double G_RadObr() const {return _RadObr;}// staly getter wartosci obrotu
		
		void S_RadObr(double S) {_RadObr=S;}// setter wartosci obrotu
	
		friend istream & operator >> (istream & StrWe, Robot & M);
		/*!
		* \zbiera dane ze strumienia wejsciowego
		* 
		* nadaje roobotowi nowe wartosci kata
		*/
		
		friend Macierz & MakeMacierz (Macierz & M, Robot & R);
		/*!
		* \zbiera macierz, i nadaje mu odpowiednie wartosci cos i sin
		* \wymaga wpisania o jaki kat nalezy obrocic prostokat i ile takich obrotow
		*ma tykonac
		* 
		* zwraca macierz z odpowiednimi wartosciami
		*/

		friend Macierz & Obrot (Macierz & M, Robot & R, double x);
		/*!
		* \zbiera macierz, i nadaje mu odpowiednie wartosci cos i sin
		* \wymaga wpisania o jaki kat nalezy obrocic prostokat i ile takich obrotow
		*ma tykonac
		* 
		* zwraca macierz z odpowiednimi wartosciami
		*/
	
		
};

	void Przesun(Robot & R);
  	/*!
	* \przemieszcza robota o zadana wartosc w uprzednio
	* \wybranym kierunku
	*
	*/

	bool Ruch(Robot R[], double a, ZbWektor A, ZbWektor B, int WybRobo);
  	/*!
	* \przemieszcza robota o zadana wartosc w uprzednio
	* \wybranym kierunku
	*
	*/

	bool Kolizja(Robot R, ZbWektor A); 
	/*!
	* \sprawdza, czy robot natrafil na przeszkode
	*
	*/

	int KolizjaRobo(Robot R[], int WybRobo);
	/*!
	* \sprawdza, czy robot natrafil na robota
	*
	*/

	double OdlegloscRobo1(Wektor A, Wektor B);
	/*!
	* \funkcaja pomocnicza dla KolizjiRobo
	*
	*/

	double OdlegloscRobo2(Wektor A, Wektor B);
	/*!
	* \funkcaja pomocnicza dla KolizjiRobo
	*
	*/

	
#endif
