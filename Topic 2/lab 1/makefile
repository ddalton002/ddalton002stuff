#creates the executable from all of the object files
lab1test: lab_1_unit_test.o lab_1.o
	g++ -Wall -g -o lab7test lab_7.o lab_7_unit_test.o

#creates the lab1 object file	
lab1: lab_1.cpp lab_1.h
	g++ -Wall -g -c lab_1.cpp

#creates the lab 1 unit test object file
lab_1_unit_test: lab_1_unit_test.cpp
	g++ -Wall -g -c lab_1_unit_test.cpp


#cleans up old .o files	
clean:
	rm *.o lab1test 