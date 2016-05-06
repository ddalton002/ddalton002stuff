/*
 * Name        : bst_node.h
 * Author      : David Dalton
 * Description : Tree lab
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class BSTNode
{
  public:
  /**
   * sets left_child_ to NULL
   * sets right_child_ to NULL
   * sets contents_ to 0
   */
   BSTNode();

  /**
   * 
   * has one int parameter for contents
   * sets left_child_ to NULL
   * sets right_child_ to NULL
   * sets contents_ to the value of the parameter
   */
   BSTNode(int value);
  /**
   *
   * sets right_child_ to NULL
   * sets left_child_ to NULL
   */
   ~BSTNode();
  
  /**
   * mutator for contents_
   */
   void set_contents(int contents);
  
  /**
   * accessors for contents_
   */
   int contents() const;
   
  /**
   * accessors for contents_
   */
   int& contents();
  
  /**
   * mutator for left_child_
   */
   void set_left_child(BSTNode* left_child);
   
  /**
   * mutator for right_child_
   */
   void set_right_child(BSTNode* right_child);
  
  /**
   * accessors for left_child_
   */
   BSTNode* left_child() const;
  /**
   * accessors for left_child_
   */
   BSTNode*& left_child();
  
  /**
   * accessors for right_child_
   */
   BSTNode* right_child() const;
  /**
   * accessors for right_child_
   */
   BSTNode*& right_child();
  
  private:
   //points to a left child
   BSTNode* left_child_;
   //points to a right child
   BSTNode* right_child_;
   //used to store the data contents of a BSTNode
   int contents_;
    
};

#endif