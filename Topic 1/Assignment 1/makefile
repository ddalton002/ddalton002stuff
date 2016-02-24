#creates the executable from both of the object files
assignment1test: assignment_1_unit_test.o assignment_1.o
	g++ -Wall -g -o assignment1test assignment_1.o assignment_1_unit_test.o

#creates the assignment_1.o object file	
lab5: assignment_1.cpp assignment_1.h
	g++ -Wall -g -c assignment_1.cpp

#creates the unit test object file
assignment_1_unit_test: assignment_1_unit_test.cpp
	g++ -Wall -g -c assignment_1_unit_test.cpp
	
#cleans up old .o files	
clean:
	rm *.o assignment1test 