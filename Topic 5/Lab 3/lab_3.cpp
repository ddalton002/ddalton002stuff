/*
 * Programming Challenge 30
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <array>
#include <list>
#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

/*
 * An Item to be stored in a HashTable.
 */
struct Item {
	Item (string newContents)
	: count(1), contents(newContents) {}

	unsigned int count;
	string contents;
};

/*
 * A class representing a hash table
 */
class HashTable {
	public:
	
		/**
		 * Insert an item into the hash table.
		 * @param i the Item to be inserted
		 */
		void insert (Item i);

		/**
		 * Remove an item from the hash table.
		 * @param contents the contents of the Item to remove
		 * @return true if an Item with the contents was removed, or false if no matching Item is found
		 */
		bool remove (string contents);

		/**
		 * Return a pointer to an Item in the hash table, by contents.
		 * @param contents the contents of the Item to return
		 * @return a pointer to the Item with the contents, or NULL if no Item matches the contents
		 */
		Item* getItem (string contents);

		/**
		 * Return the number of items currently stored in the hash table.
		 * @return an unsigned int containing the number of items stored in the hash table
		 */
		unsigned int size ();

		/**
		 * Compute the hash value for an Item object. Uses the string contents 
		 * member of Item to compute the hash. Uses the private hash function on 
		 * string contents.
		 * @param Item the Item for which to compute the hash
		 * @return an unsigned integer containing the hash computed by the private hash function
		 */
		unsigned int hash (Item i);

		/**
		 * Display a detailed view of the contents of the hash table. Format should be as follows:
		 *
		 * Items in hash table: hash_table_size
		 * [array_index] item_contents (item_count)
		 *
		 * NOTE: insert a TAB character after [array_index] and output item_contents into a field of 
		 *       width 10
		 *
		 * EXAMPLE:
		 *
		 * Items in hash table: 4
		 * [0]	     apple (1) banana (2)
		 * [1]
		 * [2]	 blueberry (1) 
		 * [3]
		 * [4]	      pear (1) 
		 *
		 * @return a string containing a detailed view of the contents of the hash table.
		 */
		string printDetail ();

	private:
		array<list<Item>, 5> items;

		/**
		 * Compute a hash value (unsigned integer) by summing the ASCII values 
		 * of the characters in a string and modding to fit the hash table size.
		 * @param s the string to hash
		 * @return an unsigned int containing the has value for the string
		 */
		unsigned int hash (string s);
};

// FUNCTION DEFINITIONS GO HERE

TEST_CASE ("hash function and hash table functionality") {
	Item items[15] = {Item("apple"), Item("banana"), Item("grape"), Item("lemon"), 
					  Item("melon"), Item("orange"), Item("strawberry"),
					  Item("pear"), Item("blueberry"), Item("grapefruit"),
					  Item("apple"), Item("banana"), Item("grape"), Item("lemon"), 
					  Item("melon")};
	HashTable ht;

	CHECK(ht.size() == 0);
	CHECK(ht.printDetail() == 
		"Items in hash table: 0\n[0]\t\n[1]\t\n[2]\t\n[3]\t\n[4]\t\n");

	CHECK(ht.hash(items[0]) == 0);
	CHECK(ht.hash(items[4]) == 4);
	CHECK(ht.hash(items[8]) == 2);
	CHECK(ht.hash(items[12]) == 2);
	CHECK(ht.hash(items[14]) == 4);

	for (Item i : items) {
		ht.insert(i);
	}

	CHECK(ht.size() == 10);

	stringstream output;
	output << "Items in hash table: 10\n" << "[0]\t     apple (2) \n";
	output << "[1]\t    orange (1) grapefruit (1) \n" << "[2]\t     grape (2)  blueberry (1) \n";
	output << "[3]\t\n";
	output << "[4]\t    banana (2)      lemon (2)      melon (2) strawberry (1)       pear (1) \n";
	CHECK(ht.printDetail() == output.str());

	Item* tempItem = ht.getItem("shoe");
	CHECK(tempItem == NULL);

	tempItem = ht.getItem("apple");
	CHECK(tempItem != NULL);
	CHECK(tempItem->count == 2);

	tempItem = ht.getItem("pear");
	CHECK(tempItem != NULL);
	CHECK(tempItem->count == 1);

	CHECK(!ht.remove("shoe"));

	CHECK(ht.remove("apple"));
	CHECK(ht.size() == 9);

	CHECK(!ht.remove("apple"));

	CHECK(ht.remove("orange"));
	CHECK(ht.remove("grapefruit"));
	CHECK(ht.remove("grape"));
	CHECK(ht.remove("blueberry"));
	CHECK(ht.remove("banana"));
	CHECK(ht.remove("lemon"));
	CHECK(ht.remove("melon"));
	CHECK(ht.remove("strawberry"));
	CHECK(ht.remove("pear"));

	CHECK(ht.size() == 0);
}