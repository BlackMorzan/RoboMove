#ifndef Sciezka_HH
#define Sciezka_HH

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <vector>

#include "Wektor.hh"

/*!
 * \file  Sciezka.hh
 *  
 *  Plik zawiera definicję klasy zapisującej ścieżkę
 *  robota
 */

/*!
 * \brief Moduł zaweira klasę pamiętającą trasę robota
 *
 * Niniejsza przestrzeń nazw stanowi moduł logiczny zawierający
 * metody zapisywania i wysyłania sciezki
 */

using namespace std;

class Sciezka
{
		vector<Wektor> _TabWek;
	
	public:
	
		Sciezka() { _TabWek.reserve(20); }
	
		void S_TabWek(Wektor & W) { _TabWek.push_back(W); }
		
		const vector<Wektor> & G_TabWek() { return _TabWek; }
	
		friend ostream & operator << (ostream & StrWy, Sciezka W);
		/*!
		* \zbiera wektory 
		* 
		* \wyswietla je
		*/
		
};

void Menu();


#endif
