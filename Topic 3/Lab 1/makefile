#creates the executable from all of the object files
lab12test: lab_12_unit_test.o lab_12.o
	g++ -Wall -g -o lab12test lab_12.o lab_12_unit_test.o

#creates the lab object file	
lab12: lab_12.cpp lab_12.h
	g++ -Wall -g -c lab_12.cpp

#creates the lab unit test object file
lab_12_unit_test: lab_12_unit_test.cpp
	g++ -Wall -g -c lab_12_unit_test.cpp


#cleans up old .o files	
clean:
	rm *.o *test 