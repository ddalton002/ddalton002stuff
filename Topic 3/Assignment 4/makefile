#creates the executable from all of the object files
sl_nodetest: lab_20_unit_test.o sl_list.o sl_node.o
	g++ -Wall -g -o lab2test sl_node.o sl_list.o lab_20_unit_test.o

#creates the node object file	
sl_node.o: sl_node.cpp sl_node.h
	g++ -Wall -g -c sl_node.cpp
	
#creates the list object file
sl_list.o: sl_list.cpp sl_list.h
	g++ -Wall -g -c sl_list.cpp

#creates the lab unit test object file
lab_20_unit_test.o: lab_20_unit_test.cpp
	g++ -Wall -g -c lab_20_unit_test.cpp

#cleans up old .o files	
clean:
	rm *.o *test 