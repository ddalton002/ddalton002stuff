#creates the executable from both of the object files
lab6test: lab_6_unit_test.o lab_6.o
	g++ -Wall -g -o lab6test lab_6.o lab_6_unit_test.o

#creates the lab6 object file	
lab6: lab_6.cpp lab_6.h
	g++ -Wall -g -c lab_6.cpp

#creates the unit test object file
lab_6_unit_test: lab_6_unit_test.cpp
	g++ -Wall -g -c lab_6_unit_test.cpp
	
#cleans up old .o files	
clean:
	rm *.o lab6test 