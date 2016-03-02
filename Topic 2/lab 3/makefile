#creates the executable from both of the object files
moneytest: lab_11_unit_test.o money.o
	g++ -Wall -g -o moneytest money.o lab_11_unit_test.o

#creates the lab6 object file	
money: money.cpp money.h
	g++ -Wall -g -c money.cpp

#creates the unit test object file
lab_11_unit_test: lab_11_unit_test.cpp
	g++ -Wall -g -c lab_11_unit_test.cpp
	
#cleans up old .o files	
clean:
	rm *.o moneytest 