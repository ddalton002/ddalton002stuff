/*
 * Name        : bst_node.cpp
 * Author      : David Dalton
 * Description : Tree lab
 */
 
#include "bst_node.h"

/**
 * sets left_child_ to NULL
 * sets right_child_ to NULL
 * sets contents_ to 0
 */
BSTNode::BSTNode ()
{
    set_left_child(NULL);
    set_right_child(NULL);
    set_contents(0);
}

/** 
 * 
 * has one int parameter for contents
 * sets left_child_ to NULL
 * sets right_child_ to NULL
 * sets contents_ to the value of the parameter
 */
BSTNode::BSTNode(int value) 
{
    set_left_child(NULL);
    set_right_child(NULL);
    set_contents(value);
}
/**
 *
 * sets right_child_ to NULL
 * sets left_child_ to NULL
 */
BSTNode::~BSTNode()
{
    set_left_child(NULL);
    set_right_child(NULL);
}
  
/**
 * mutator for contents_
 */
void BSTNode::set_contents(int contents) 
{
    contents_ = contents;
}
  
/**
 * accessors for contents_
 */
int BSTNode::contents() const 
{
    return contents_;
}
   
/**
 * accessors for contents_
 */
int& BSTNode::contents() 
{
    return contents_;
}
  
/**
 * mutator for left_child_
 */
void BSTNode::set_left_child(BSTNode* left_child)
{
    left_child_ = left_child;
}
   
/**
 * mutator for right_child_
 */
void BSTNode::set_right_child(BSTNode* right_child) 
{
    right_child_ = right_child;
}
  
/**
 * accessors for left_child_
 */
BSTNode* BSTNode::left_child() const 
{
    return left_child_;
}
/**
 * accessors for left_child_
 */
BSTNode*& BSTNode::left_child() 
{
    return left_child_;
}
  
/**
 * accessors for right_child_
 */
BSTNode* BSTNode::right_child() const 
{
    return right_child_;
}
/**
 * accessors for right_child_
 */
BSTNode*& BSTNode::right_child() 
{
    return right_child_;
}