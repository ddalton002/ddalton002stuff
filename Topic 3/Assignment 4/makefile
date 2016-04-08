#creates the executable from all of the object files
chairstest: chairs.o dl_list.o dl_node.o
	g++ -Wall -g -o lab2test dl_node.o dl_list.o chairs.o

#creates the node object file	
dl_node.o: dl_node.cpp dl_node.h
	g++ -Wall -g -c dl_node.cpp
	
#creates the list object file
dl_list.o: dl_list.cpp dl_list.h
	g++ -Wall -g -c dl_list.cpp

#creates the chair object file
chairs.o: chairs.cpp CinReader.cpp CinReader.h 
	g++ -Wall -g -c chairs.cpp CinReader.cpp

#cleans up old .o files	
clean:
	rm *.o *test 