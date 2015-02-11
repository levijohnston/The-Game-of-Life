#this Makefile goes in the src directory

EXECUTABLE := gameoflife

# the source files to be built
SOURCES := *.cpp


INCLUDES := -I ../include
LIBS := -lm
EXT := exe
CC := g++

all:
	$(CC) $(INCLUDES) $(LIBS) $(SOURCES) -o $(EXECUTABLE).$(EXT)

realclean:
	find . -type f -name "*.o" -exec rm '{}' \;
	find . -type f -name "*.exe" -exec rm '{}' \;

# this line required by make - don't delete
