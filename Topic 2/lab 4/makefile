
#creates the executable from both of the object files
itemtest: lab_10_unit_test.o item.o food_item.o magic_item.o
	g++ -Wall -g -o itemtest lab_10_unit_test.o item.o food_item.o magic_item.o

#creates the item object file	
item.o: item.cpp item.h
	g++ -Wall -g -c item.cpp

#creates the fooditem object file
fooditem.o: food_item.cpp food_item.h
	g++ -Wall -g -c food_item.cpp
	
#creates the magicitem object file
magicitem.o: magic_item.cpp magic_item.h
	g++ -Wall -g -c magic_item.cpp

#creates the unit test object file
lab_10_unit_test.o: lab_10_unit_test.cpp
	g++ -Wall -g -c lab_10_unit_test.cpp
	
#cleans up old .o files	
clean:
	rm *.o itemtest 