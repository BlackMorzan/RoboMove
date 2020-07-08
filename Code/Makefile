#
#  To sa opcje dla kompilacji

CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++11 -fPIE

__start__: a.out
	./a.out

a.out: obj/main.o obj/Wektor.o obj/ZbWektor.o obj/Macierz.o obj/lacze_do_gnuplota.o obj/Robot.o obj/Sciezka.o obj/All.o
	g++ -Wall -pedantic -o a.out obj/main.o obj/Wektor.o obj/ZbWektor.o obj/Macierz.o obj/Robot.o obj/lacze_do_gnuplota.o obj/Sciezka.o obj/All.o

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh 
	g++ ${CPPFLAGS} -o obj/Wektor.o src/Wektor.cpp
	
obj/ZbWektor.o: src/ZbWektor.cpp inc/Wektor.hh inc/ZbWektor.hh 
	g++ ${CPPFLAGS} -o obj/ZbWektor.o src/ZbWektor.cpp
	
obj/Macierz.o: src/Macierz.cpp inc/Wektor.hh inc/ZbWektor.hh inc/Macierz.hh
	g++ ${CPPFLAGS} -o obj/Macierz.o src/Macierz.cpp
	
obj/Robot.o: src/Robot.cpp inc/Wektor.hh inc/ZbWektor.hh inc/Macierz.hh inc/Robot.hh
	g++ ${CPPFLAGS} -o obj/Robot.o src/Robot.cpp

obj/lacze_do_gnuplota.o: src/lacze_do_gnuplota.cpp inc/lacze_do_gnuplota.hh
	g++ ${CPPFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/Sciezka.o: src/Sciezka.cpp inc/Wektor.hh inc/Sciezka.hh 
	g++ ${CPPFLAGS} -o obj/Sciezka.o src/Sciezka.cpp

obj/All.o: src/All.cpp inc/Wektor.hh inc/lacze_do_gnuplota.hh inc/ZbWektor.hh inc/Macierz.hh inc/Robot.hh inc/Sciezka.hh inc/All.hh
	g++ ${CPPFLAGS} -o obj/All.o src/All.cpp

obj/main.o: src/main.cpp inc/Wektor.hh inc/lacze_do_gnuplota.hh inc/ZbWektor.hh inc/Macierz.hh inc/Robot.hh inc/Sciezka.hh inc/All.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp


clean:
	rm -f obj/*.o a.out
