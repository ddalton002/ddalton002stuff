/*
 * Name        : sl_node.h
 * Author      : David Dalton
 * Description : Header File for Lab 2.
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::endl;
using std::string;

class SLNode 
{
  public:
  /*
   *Default Constructor
   *--sets next_node_ to NULL
   *--sets contents_ to 0
   */
   SLNode();
  /*
   *Overloaded Constructor
   *--int parameter assigned to contents_
   *--sets next_node to NULL
   */
   SLNode(int contents);
  /*
   *Destructor
   *--does nothing
   */
   ~SLNode();
  /*
   *void set_contents(int)
   *--mutator for contents_
   */
   void set_contents(int contents);
   /*
   *int contents() const
   *--accessor for contents_
   */
   int contents();
  /*
   *void set_next_node(SLNode*)
   *--mutator for next_node_
   */
   void set_next_node(SLNode* next_node);
   /*
   *SLNode* next_node() const
   *--accessor for next_node_
   */
   SLNode* next_node() const;
  
  private:
   SLNode* next_node_;
   int contents_;
};

#endif