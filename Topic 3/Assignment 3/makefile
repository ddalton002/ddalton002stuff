#creates the executable from all of the object files
lab2play: driver.o box.o prize.o
	g++ -Wall -g -o lab2play prize.o box.o driver.o

#creates the driver functions
cinreader: CinReader.cpp CinReader.h
	g++ -Wall -g -c CinReader.cpp

#creates the driver functions
driver: driver.cpp
	g++ -Wall -g -c driver.cpp 

#creates the executable from all of the object files
lab2test: assign_3_unit_test.o prize.o box.o
	g++ -Wall -g -o lab2test prize.o box.o assign_3_unit_test.o

#creates the prize object file
prize: prize.cpp.cpp prize.h
	g++ -Wall -g -c prize.cpp

#creates the box object file
box: box.cpp box.h
	g++ -Wall -g -c box.cpp

#creates the unit test object file
assign_3_unit_test: assign_3_unit_test.cpp
	g++ -Wall -g -c assign_3_unit_test.cpp

#cleans up old .o files	
clean:
	rm *.o *test  *play