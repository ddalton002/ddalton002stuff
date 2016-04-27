/*
 * Name        : bst_tree.h
 * Author      : David Dalton
 * Description : Tree lab
 */
 
#include "bs_tree.h"

/**
 * sets root_ to NULL
 * sets size_ to 0
 */
BSTree::BSTree() 
{
    root_ = NULL;
    size_ = 0;
}

/**
 * calls Clear()
 */
BSTree::~BSTree()
{
    Clear();
}

/**
 * calls private function Insert(int, root)
 */
bool BSTree::Insert(int value) 
{
    return Insert(value,root_);
}

/** 
 * calls private function Clear(root)
 */
void BSTree::Clear() 
{
    Clear(root_);
}

/**
 * Accessor for size_
 */
unsigned int BSTree::size() const 
{
    return size_;
}

/**
 * calls private function InOrder(root)
 */
string BSTree::InOrder() 
{
    return InOrder(root_);
}

/**
 * creates a new BSTNode, inserts it into the tree, and returns true
 * if the integer is already in the tree, does not insert, and
 * returns false
 */
bool BSTree::Insert(int value, BSTNode*& node) 
{
    BSTNode* insertNode = new BSTNode(value);
    /**
     * Checks if the root is null, and creates a new node if it is
     */
    if(node == NULL)
    {
      node = insertNode;
      size_ = size_ + 1;
      return true;
    /**
     * Checks if the contents of root are greater then the contents of the 
     * new node
     */
    } else if(node->contents() > value)
    {
        /**
         * Checks if the left child of root is null and inserts the node
         * there if it is, else it calls the insert function with the value
         * and the contents of the roots left child
         */
        Insert(value, node->left_child());
    /**
     * Checks if the contents of root are less than the contents of the
     * new node
     */
    } else if(node->contents() < value)
    {
        /**
         * Checks if the right child of root is null and inserts the node
         * there if it is, else it calls the insert function with the value
         * and the contents of the roots right child
         */
        Insert(value, node->right_child());
    } 
    /**
     * Checks if the contents of root is equal to the insure value
     */
    else
    {
      return false;
    }
}

/**
 * clears the entire contents of the tree,
 * freeing all memory associated with all nodes
 */
void BSTree::Clear(BSTNode*& node) 
{
    /**
     * Checks to make sure that the tree is not already empty
     */
    if (node != NULL)
    {
        /**
         * Checks if both childs of the root are null and deletes the root
         * if they are
         */
        if (node->left_child() == NULL && node->right_child() == NULL)
        {
            delete node;
            node = NULL;
        /**
         * If either of the roots child nodes has contents then it calls the
         * Clear function again on the current node in the tree being looked at
         */
        } else
        {
            if (node->left_child())
            {
                Clear(node->left_child());
            } 
            if (node->right_child())
            {
                Clear(node->right_child());
            }
        }
    size_ = size_ - 1;
    node = NULL;
    }
}

/**
 * creates a string of the data in all nodes in the tree, in
 * ascending order
 * separate by spaces (there should be a space after the last output
 * value)
 */
string BSTree::InOrder(BSTNode* node) 
{
    stringstream output;
    if (node == NULL)
    {
    return output.str();
    }
    else 
    {
        output << InOrder(node->left_child());
        output << node->contents() << " ";
        output << InOrder(node->right_child());
    return output.str();
    }
}