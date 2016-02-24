# makefile example for CSCI 21
# uses the catch unit test framework to test lab 2

#name of the executable file
all: lab2test

#creates the executable from the object files
lab2test: lab_2_unit_test.o lab_2.o
    g++ -Wall -g -o lab2test lab_2.o lab_2_unit_test.o
    
#creates the lab2 object file
lab2: lab2.cpp
    g++ -Wall -g -c lab_2.cpp
        
# creates the unit test object file
lab2_unittest: lab2_unittest.cpp
   g++ -Wall -g -c lab_2_unit_test.cpp
   
   
# to run the make file,t ype inmake.