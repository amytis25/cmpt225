all: testcirc1 testcirc2 circleTest

circleTest: circleTest.o Circle.o
	g++ -Wall circleTest.o Circle.o -o circleTest

testcirc1: testcirc1.o Circle.o
	g++ -Wall testcirc1.o Circle.o -o testcirc1

testcirc2: testcirc2.o Circle.o
	g++ -Wall testcirc2.o Circle.o -o testcirc2

Circle.o: Circle.h Circle.cpp
	g++ -Wall -c Circle.cpp

testcirc1.o: testcirc1.cpp Circle.h
	g++ -Wall -c testcirc1.cpp

testcirc2.o: testcirc2.cpp Circle.h
	g++ -Wall -c testcirc2.cpp

circleTest.o: circleTest.cpp Circle.h
	g++ -Wall -c circleTest.cpp 

clean:
	rm -f testcirc1 testcirc2 circleTest *.o