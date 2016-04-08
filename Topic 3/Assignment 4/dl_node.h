/**
 * Name: dl_node.h
 * Author: David Dalton
 * Sources:
 */
 
#ifndef NODE_H
#define NODE_h

#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::istream;
 
/**
 * A DLNode Class for a double linked list
 */
class DLNode 
{
    public:
    /**
     * initialize contents to zero, next and previous to NULL
     */
     DLNode();
    /**
     * initialize contents to newContents, next and previous to NULL
     */
     DLNode(int newContents);
    /**
     * nothing to be done
     */
     virtual ~DLNode();
    /**
     * 
     */
     void setContents(int newContents);
    /**
     * 
     */
     void setNext(DLNode* newNext);
    /**
     * 
     */
     void setPrevious(DLNode* newPrevious);
    /**
     * 
     */
     int getContents() const;
    /**
     * 
     */
     DLNode* getNext() const;
    /**
     * 
     */
     DLNode* getPrevious() const;
     
    private:
     DLNode* next_node_;
     DLNode* previous_node_;
     int contents_;
};

#endif