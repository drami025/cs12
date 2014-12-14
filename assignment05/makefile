all: BBoard.o Message.o User.o BBoard.h Message.h User.h
	g++ -W -Wall -Werror -ansi -pedantic main.cpp BBoard.o Message.o User.o -o main.out
	
BBoard.o: BBoard.cpp Message.o User.o BBoard.h
	g++ -W -Wall -Werror -ansi -pedantic -c BBoard.cpp 
	
Message.o: Message.cpp Message.h
	g++ -W -Wall -Werror -ansi -pedantic -c Message.cpp
	
User.o: User.cpp User.h
	g++ -W -Wall -Werror -ansi -pedantic -c User.cpp
	
