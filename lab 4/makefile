#creates the executable from both of the object files
lab4test: lab_4_unit_test.o lab_4.o
	g++ -Wall -g -o lab4test lab_4.o lab_4_unit_test.o

#creates the lab4 object file	
lab4: lab_4.cpp lab_4.h
	g++ -Wall -g -c lab_4.cpp

#creates the unit test object file
lab_4_unit_test: lab_4_unit_test.cpp
	g++ -Wall -g -c lab_4_unit_test.cpp

#cleans up old .o files	
clean:
	rm *.o lab4