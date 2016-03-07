#creates the executable from both of the object files
assignment1test: assignment_2_unit_test.o assignment_2.o
	g++ -Wall -g -o assignment2test assignment_2.o assignment_2_unit_test.o

#creates the assignment_1.o object file	
assignment2: assignment_2.cpp assignment_2.h
	g++ -Wall -g -c assignment_2cpp

#creates the unit test object file
assignment_2_unit_test: assignment_2_unit_test.cpp
	g++ -Wall -g -c assignment_2_unit_test.cpp
	
#cleans up old .o files	
clean:
	rm *.o assignment2test 