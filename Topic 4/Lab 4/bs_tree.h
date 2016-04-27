/*
 * Name        : bst_tree.h
 * Author      : David Dalton
 * Description : Tree lab
 */

#ifndef TREE_H
#define TREE_H

#include "bst_node.h"
#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class BSTree 
{
  public:
    /**
     * sets root_ to NULL
     * sets size_ to 0
     */
    BSTree();
    
    /**
     * calls Clear()
     */
    ~BSTree();
    
    /**
     * calls private function Insert(int, root)
     */
    bool Insert(int value);
    
    /** 
     * calls private function Clear(root)
     */
    void Clear();
    
    /**
     * Accessor for size_
     */
    unsigned int size() const;
    
    /**
     * calls private function InOrder(root)
     */
    string InOrder();
    
  private:
    /**
     * creates a new BSTNode, inserts it into the tree, and returns true
     * if the integer is already in the tree, does not insert, and
     * returns false
     */
    bool Insert(int value, BSTNode*& node);
    
    /**
     * clears the entire contents of the tree,
     * freeing all memory associated with all nodes
     */
    void Clear(BSTNode*& node);
    
    /**
     * creates a string of the data in all nodes in the tree, in
     * ascending order
     * separate by spaces (there should be a space after the last output
     * value)
     */
    string InOrder(BSTNode* node);
    
    /**
     * points to the root node of a binary search tree
     */
    BSTNode* root_;
    
    /**
     * holds the number of nodes in the tree
     */
    unsigned int size_;
};

#endif