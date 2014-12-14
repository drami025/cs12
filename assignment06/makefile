all: IntVector.o IntVector.h
	g++ -W -Wall -Werror -ansi -pedantic main.cpp IntVector.o -o main.out
	
IntVector.o: IntVector.cpp IntVector.h
	g++ -W -Wall -Werror -ansi -pedantic -c IntVector.cpp