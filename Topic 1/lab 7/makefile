#creates the executable from all of the object files
lab7test: lab_7_unit_test.o lab_7.o
	g++ -Wall -g -o lab7test lab_7.o lab_7_unit_test.o

#creates the lab7 object file	
lab7: lab_7.cpp lab_7.h
	g++ -Wall -g -c lab_7.cpp

#creates the lab 7 unit test object file
lab_7_unit_test: lab_7_unit_test.cpp
	g++ -Wall -g -c lab_7_unit_test.cpp
	
#creates the executable from all of the object files
lab8test: lab_8_unit_test.o lab_7.o
	g++ -Wall -g -o lab8test lab_7.o lab_8_unit_test.o
	
#creates the lab 8 unit test object file
lab_8_unit_test: lab_8_unit_test.cpp
	g++ -Wall -g -c lab_8_unit_test.cpp	

#cleans up old .o files	
clean:
	rm *.o lab7test  lab8test