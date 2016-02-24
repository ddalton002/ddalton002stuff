#creates the executable from both of the object files
lab5test: lab_5_unit_test.o lab_5.o
	g++ -Wall -g -o lab5test lab_5.o lab_5_unit_test.o

#creates the lab5 object file	
lab5: lab_5.cpp lab_5.h
	g++ -Wall -g -c lab_5.cpp

#creates the unit test object file
lab_5_unit_test: lab_5_unit_test.cpp
	g++ -Wall -g -c lab_5_unit_test.cpp
	
#cleans up old .o files	
clean:
	rm *.o lab5test