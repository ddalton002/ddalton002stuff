/*
 * Name        : sl_list.h
 * Author      : David Dalton
 * Description : Header File for lab 3 sl_list.
 */

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <sstream>
#include "sl_node.h"
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class SLList 
{
 public:
 /*
  Default Constructor
  --sets head_ to NULL
  --sets size_ to 0
  */
  SLList();
  /*
  Destructor
  --calls Clear()
  */
  ~SLList();
  /*
  void Clear()
  --clears the entire contents of the list,
    freeing all memory associated with all nodes
  */
  void Clear();
  /*
  --creates a new SLNode with the contents of the parameter and
    inserts it into the correct position in the list. The list
    will be sorted with the lowest values in the front (head) and the
    largest values in the back (tail).
   */
  void Insert(int insert);
  /*
  --remove the first occurence of the supplied parameter
    found as the data of a node. Return true on successful
    removal or false if the list is empty or if the value
    is not found.
   */
  bool RemoveFirstOccurence(int parameter);
  /*
	-- Returns the contents of the head node
     (The node head_ is pointing to)
     Returns 0 if the list is empty
    */
  int GetHead() const;
  /*
  -- Returns the contents of the tail node
     (The node tail_ is pointing to)
     Returns 0 if the list is empty
    */
  int GetTail() const;
  /*
  unsigned int size() const
  --accessor for size_
  */
  unsigned int size() const;
  /*
  string ToString() const
  --returns a string representation of the contents
    of all nodes in the list, in the format
    NUM1, NUM2, ..., LASTNUM
    returns the empty string on an empty list (i.e. returns "")
    */
  string ToString();
    
 private:
  /*
  void InsertHead(int)
  --creates a new dynamic SLNode with the contents of 
    the parameter and attaches as the new head of the list
  */
  void InsertHead(int insert);
  /*
	--creates a new dynamic SLNode with the contents of 
		the parameter and attaches as the last node (tail) of the list
	 */
  void InsertTail(int insert);
  /*
  void RemoveHead()
  --removes the head node from the list,
    or does nothing if the list is empty
  */
  void RemoveHead();
  /*
  --removes the last node (tail) from the list,
	  or does nothing if the list is empty
	 */
	void RemoveTail();
  //points to the last node in a singly-linked list
	SLNode* tail_;
  //points to the first node in a singly-linked list
  SLNode* head_;
  //stores the count of the number of nodes in the list
  unsigned int size_;
};

#endif