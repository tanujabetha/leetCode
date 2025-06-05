# Target to build everything
all: graphApp

# Link object files to create the final executable
graphApp: main.o MatrixBuild.o Traversals.o DetectingCycle.o
	g++ main.o MatrixBuild.o Traversals.o DetectingCycle.o -o graphApp

# Compile main.cpp into main.o
main.o: main.cpp MatrixBuild.h Traversals.h DetectingCycle.h
	g++ -c main.cpp


MatrixBuild.o: MatrixBuild.cpp MatrixBuild.h
	g++ -c MatrixBuild.cpp

# Compile Traversals.cpp into Traversals.o
Traversals.o: Traversals.cpp Traversals.h MatrixBuild.h
	g++ -c Traversals.cpp

# Compile DetectingCycle.cpp into DetectingCycle.o
DetectingCycle.o: DetectingCycle.cpp DetectingCycle.h MatrixBuild.h
	g++ -c DetectingCycle.cpp

# Clean up object files and executable
clean:
	rm -f *.o graphApp
