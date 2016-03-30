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
  void InsertHead(int)
  --creates a new dynamic SLNode with the contents of 
    the parameter and attaches as the new head of the list
  */
  void InsertHead(int insert);
  /*
  void RemoveHead()
  --removes the head node from the list,
    or does nothing if the list is empty
  */
  void RemoveHead();
  /*
  void Clear()
  --clears the entire contents of the list,
    freeing all memory associated with all nodes
  */
  void Clear();
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
  //points to the first node in a singly-linked list
  SLNode* head_;
  //stores the count of the number of nodes in the list
  unsigned int size_;
};

#endif