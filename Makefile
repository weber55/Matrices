all: p1

p1: p1.o Matrix.o
	g++ -o p1 p1.o Matrix.o

p1.o: p1.cpp Matrix.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c p1.cpp 

Matrix.o: Matrix.cpp Matrix.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c Matrix.cpp

clean:
	rm -f p1
	rm -f p1.o

