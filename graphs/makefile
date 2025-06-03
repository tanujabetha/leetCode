all: graphApp

graphApp: main.o MatrixBuild.o Traversals.o
	g++ main.o MatrixBuild.o Traversals.o -o graphApp

main.o: main.cpp MatrixBuild.h Traversals.h
	g++ -c main.cpp

MatrixBuild.o: MatrixBuild.cpp MatrixBuild.h
	g++ -c MatrixBuild.cpp

Traversals.o: Traversals.cpp Traversals.h MatrixBuild.h
	g++ -c Traversals.cpp

clean:
	rm -f *.o graphApp
