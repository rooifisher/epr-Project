CC=g++
CFLAGS = `pkg-config opencv --cflags`

LIBS = `pkg-config opencv --libs`

CFLAGS2 = `pkg-config fann --cflags`
LIBS2 = `pkg-config fann --libs`
SOURCES1= numPlate.cpp
SOURCES2= loadImage.cpp
SOURCES3= neuralNetwork.cpp
SOURCES4 = neuralTest.cpp
SOURCES5 = letterExtraction.cpp
SOURCES6 = extractColour.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE1=numPlate
EXECUTABLE2=loadImage
EXECUTABLE3=neural
EXECUTABLE4= neuralTest
EXECUTABLE5 = letterExtraction
EXECUTABLE6 = colour

all:
	make clean
	make numPlate
	make loadImage
	make neural
	make test
	make extract 
	make colour
	
numPlate: 
	rm -f $(EXECUTABLE1)
	$(CC) $(CFLAGS) $(SOURCES1) -o $(EXECUTABLE1) $(LIBS)
loadImage:
	rm -f $(EXECUTABLE2)
	$(CC) $(CFLAGS) $(SOURCES2) -o $(EXECUTABLE2) $(LIBS)
neural:
	rm -f $(EXECUTABLE3)
	$(CC) $(CFLAGS2) $(SOURCES3) -o $(EXECUTABLE3) $(LIBS2)
test:
	rm -f $(EXECUTABLE4)
	$(CC) $(CFLAGS2) $(SOURCES4) -o $(EXECUTABLE4) $(LIBS2)

extract:
	rm -f $(EXECUTABLE5)
	$(CC) $(CFLAGS) $(SOURCES5) -o $(EXECUTABLE5) $(LIBS)
	
colour:
	rm -f $(EXECUTABLE6)
	$(CC) $(CFLAGS) $(SOURCES6) -o $(EXECUTABLE6) $(LIBS)	
clean:
	rm   -f $(EXECUTABLE1) $(EXECUTABLE2) $(EXECUTABLE3) $(EXECUTABLE4) $(EXECUTABLE5) $(EXECUTABLE6)


