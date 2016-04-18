#creates the executable from all of the object files
lab2test: lab_22_unit_test.o lab_22.o
	g++ -Wall -g -o lab22test lab_22.o lab_22_unit_test.o

#creates the lab1 object file	
lab22: lab_22.cpp lab_22.h
	g++ -Wall -g -c lab_1.cpp

#creates the lab 1 unit test object file
lab_22_unit_test: lab_22_unit_test.cpp
	g++ -Wall -g -c lab_22_unit_test.cpp

#cleans up old .o files	
clean:
	rm *.o *test 