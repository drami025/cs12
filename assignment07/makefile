all: main.o IntList.o
	g++ -W -Wall -ansi -pedantic main.o IntList.o -o main.out
	
main.o: main.cpp
	g++ -W -Wall -ansi -pedantic -c main.cpp

IntList.o: IntList.cpp IntList.h
	g++ -W -Wall -ansi -pedantic -c IntList.cpp