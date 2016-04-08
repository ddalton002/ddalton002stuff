/**
 * Name: dl_list.h
 * Author: David Dalton
 * Sources:
 */
 
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <sstream>
#include "dl_node.h"
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::ostream;
using std::istream;

 
/**
 * A DLList class to contain all of the functionality of a doubly-linked list: 
 * push front, pushback, pop front, pop back, insert (sorted), remove, 
 * retrieve, overloaded operator <<,constructor, destructor, clear, size
 */
class DLList
{
    public:
    /**
     * Default Constructor
     * initialize count to zero, head and tail to NULL
     */
     DLList();
    /**
     * Destructor
     * call clear function
     */
     ~DLList();
    /**
     * Accessor for count_
     * return count
     */
     unsigned int getSize() const;
    /**
     * create new DLNode with newContents and attach at head
     */
     void pushFront(int newContents);
    /**
     * create new DLNode with newContents and attach at tail
     */
     void pushBack(int newContents);
    /**
     * create new DLNode with newContents and insert in ascending (based on 
     * newContents) order
     */
     void insert(int newContents);
    /**
     * return the value of the contents of the head node; throw an exception 
     * (throw "LIST EMPTY") if the list is empty
     */
     int getFront() const;
    /**
     * return the value of the contents of the tail node; throw an exception 
     * (throw "LIST EMPTY") if the list is empty
     */
     int getBack() const;
    /**
     * return true if target is in list, else return false
     */
     bool get(int target) const;
    /**
     * remove current head node; do nothing if list is empty
     */
     void popFront();
    /**
     * remove current tail node; do nothing if list is empty
     */
     void popBack();
    /**
     * remove the first instance of a DLNode containing target; do nothing if 
     * target is not found
     */
     bool removeFirst(int target);
    /**
     * remove all instances of DLNode containing target; do nothing if target 
     * is not found
     */
     bool removeAll(int target);
    /**
     * clear all nodes from list, reset count to zero, set head and tail to NULL
     */
     void clear();
    /**
     * display the contents of each node in the list, formatted per the 
     * program specification ("NUM1,NUM2,NUM3,...,NUMX"), to the output stream 
     * out
     */
     friend ostream& operator <<(ostream &out, const DLList &src);
  
    private:
     DLNode* head_;
     DLNode* tail_;
     unsigned int count_;
};

#endif