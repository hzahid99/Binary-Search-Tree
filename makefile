lab10: main.o Executive.o Pokemon.o
	g++ -std=c++11 -g -Wall main.o Executive.o Pokemon.o -o lab10

main.o: main.cpp Executive.h Pokemon.h BNode.h BNode.cpp BSTInterface.h BST.h BST.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

Pokemon.o: Pokemon.h Pokemon.cpp
	g++ -std=c++11 -g -Wall -c Pokemon.cpp

clean:
	rm *.o lab10
