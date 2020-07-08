#ifndef ALL_HH
#define ALL_HH


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

/*!
 * \file  All.hh
 *  
 *  Plik zawiera interface ruchu robota
 *  i funkce udrzucajaca inne znaki niz cyfry
 */

/*!
 * \brief Moduł zawierający podstawową funcje programu
 *
 * Niniejsza przestrzeń nazw stanowi moduł logiczny zawierający
 * interface programu
 */

using namespace std;

	void All();
	/*!
	* \podstatowa funkcja zawierajaca caly program
	*
	*/

	double Read();
	/*!
	* \funkca pozwala wczytywac tylko liczby
	*
	*/

#endif
