tictacmath : board.o input.o main.o boardchecker.o winChecker.o
	g++ -o tictacmath board.o input.o main.o boardchecker.o winChecker.o

main.o : main.cc board.h input.h
	g++ -Wall -c main.cc
board.o : board.cc board.h input.h
	g++ -Wall -c board.cc
input.o : input.cc input.h board.h
	g++ -Wall -c input.cc
boardchecker.o : boardchecker.cc boardchecker.h
	g++ -Wall -c boardchecker.cc
winChecker.o : winChecker.cc winChecker.h
	g++ -Wall -c winChecker.cc
clean :
	rm tictacmath board.o input.o main.o boardchecker.o winChecker.o 
