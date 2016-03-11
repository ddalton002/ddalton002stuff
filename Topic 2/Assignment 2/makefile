#creates the executable from both of the object files
atmtest:  bank_account.o checking_account.o savings_account.o credit_account.o
	g++ -Wall -g -o atmtest bank_account.o checking_account.o savings_account.o credit_account.o

#creates the bank_account object file	
bank_account.o: bank_account.cpp bank_account.h
	g++ -Wall -g -c bank_account.cpp

#creates the checking_account object file
checking_account.o: checking_account.cpp checking_account.h
	g++ -Wall -g -c checking_account.cpp
	
#creates the savings_account object file
savings_account.o: savings_account.cpp savings_account.h
	g++ -Wall -g -c savings_account.cpp

#creates the credit_account object file
credit_account.o: credit_account.cpp credit_account.h
	g++ -Wall -g -c credit_account.cpp

#creates the CinReader object file
CinReader.o: CinReader.cpp CinReader.h
	g++ -Wall -g -c CinReader.cpp

#creates the unit test object file
#atm_test.o: atm_test.cpp CinReader.o - atm_test.o
#	g++ -Wall -g -c atm_test.cpp CinReader.o - atm_test.o 
	
#cleans up old .o files	
clean:
	rm *.o *test 