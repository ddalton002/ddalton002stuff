#creates the executable from both of the object files
itemtest: lab_10_unit_test.o item.o
	g++ -Wall -g -o itemtest item.o lab_10_unit_test.o

#creates the lab6 object file	
item: item.cpp item.h
	g++ -Wall -g -c item.cpp

#creates the unit test object file
lab_10_unit_test: lab_10_unit_test.cpp
	g++ -Wall -g -c lab_10_unit_test.cpp
	
#cleans up old .o files	
clean:
	rm *.o itemtest 