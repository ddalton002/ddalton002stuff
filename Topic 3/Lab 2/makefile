#creates the executable from all of the object files
sl_nodetest: lab_17_unit_test.o sl_node.o
	g++ -Wall -g -o lab2test sl_node.o lab_17_unit_test.o

#creates the lab object file	
sl_node: sl_node.cpp sl_node.h
	g++ -Wall -g -c sl_node.cpp

#creates the lab unit test object file
lab_17_unit_test: lab_17_unit_test.cpp
	g++ -Wall -g -c lab_17_unit_test.cpp


#cleans up old .o files	
clean:
	rm *.o *test 