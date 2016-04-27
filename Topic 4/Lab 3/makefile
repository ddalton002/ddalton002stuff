#creates the executable from objects
lab23test: lab_23_unit_test.o bst_node.o
	g++ -Wall -g -o lab2test lab_23_unit_test.o bst_node.o

#creates the bst_node object file
bst_node: bst_node.cpp bst_node.h
	g++ -Wall -g -c bst_node.cpp
	
#creates the lab23 unit test object
lab_23_unit_test: lab_23_unit_test.cpp
	g++ -Wall -g -c lab_23_unit_test.cpp
	
#removes all object files and exe	
clean:
	rm *.o assign4test