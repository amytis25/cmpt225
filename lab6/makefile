all: lab6

lab6: Lab6TestDriver.o Queue.o Profile.o EmptyDataCollectionException.o
	g++ -o lab6 Lab6TestDriver.o Queue.o Profile.o EmptyDataCollectionException.o

# Note, this makefile is very strong in terms of dependencies.
# It assumes most classes can depend on others, just to be safe.
# This results in much redundant compilation, and one could remove some of these dependencies.

Lab6TestDriver.o: Lab6TestDriver.cpp Queue.h Profile.h EmptyDataCollectionException.h
	g++ -c Lab6TestDriver.cpp
	
Queue.o: Queue.cpp Queue.h Profile.h EmptyDataCollectionException.h
	g++ -c Queue.cpp

Profile.o: Profile.cpp Profile.h
	g++ -c Profile.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h
	g++ -c EmptyDataCollectionException.cpp

clean:
	rm -f lab6 *.o
