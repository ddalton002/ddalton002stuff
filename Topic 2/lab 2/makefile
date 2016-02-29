#creates the executable from both of the object files
temperaturetest: lab_10_unit_test.o temperature.o
	g++ -Wall -g -o temperaturetest temperature.o lab_10_unit_test.o

#creates the lab6 object file	
temperature: temperature.cpp temperature.h
	g++ -Wall -g -c temperature.cpp

#creates the unit test object file
lab_10_unit_test: lab_10_unit_test.cpp
	g++ -Wall -g -c lab_10_unit_test.cpp
	
#cleans up old .o files	
clean:
	rm *.o temperaturetest 