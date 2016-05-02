#creates the executable from objects
lab25test: lab_25_unit_test.o bst_node.o bs_tree.o
	g++ -Wall -g -o lab2test lab_25_unit_test.o bst_node.o bs_tree.o

#creates the bs_tree object
bs_tree: bs_tree.cpp bs_tree.h
	g++ -Wall -g -c bs_tree.cpp
	
#creates the bst_node object file
bst_node: bst_node.cpp bst_node.h
	g++ -Wall -g -c bst_node.cpp
	
#creates the lab24 unit test object
lab_25_unit_test: lab_25_unit_test.cpp
	g++ -Wall -g -c lab_25_unit_test.cpp
	
#removes all object files and exe	
clean:
	rm *.o *test