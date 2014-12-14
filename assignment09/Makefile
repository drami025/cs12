all: main.o BBoard.o Message.o Reply.o Topic.o User.o
	g++ -W -Wall -ansi -pedantic main.o BBoard.o Message.o Reply.o Topic.o User.o -o main.out
	
main.o: main.cpp
	g++ -W -Wall -ansi -pedantic -c main.cpp

BBoard.o: BBoard.cpp BBoard.h Message.o Reply.o Topic.o User.o
	g++ -W -Wall -ansi -pedantic -c BBoard.cpp
	
Reply.o: Reply.cpp Message.o Reply.h
	g++ -W -Wall -ansi -pedantic -c Reply.cpp
	
Topic.o: Topic.cpp Message.o Topic.h
	g++ -W -Wall -ansi -pedantic -c Topic.cpp
	
Message.o: Message.cpp Message.h
	g++ -W -Wall -ansi -pedantic -c Message.cpp
	
User.o: User.h User.cpp
	g++ -W -Wall -ansi -pedantic -c User.cpp