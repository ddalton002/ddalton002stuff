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
    if(root_ == NULL)
    {
      root_ = insertNode;
      size_ = size_ + 1;
    /**
     * Checks if the contents of root is equal to the insure value
     */
    } else if(root_->contents() == insertNode->contents())
    {
      return false;
    /**
     * Checks if the contents of root are greater then the contents of the 
     * new node
     */
    } else if(root_->contents() > insertNode->contents())
    {
        /**
         * Checks if the left child of root is null and inserts the node
         * there if it is, else it calls the insert function with the value
         * and the contents of the roots left child
         */
        if(root_->left_child() == NULL){
            //root_->set_left_child(insertNode);
            size_ = size_ + 1;
        } else
        {
            Insert(value, node->left_child());
        }
    /**
     * Checks if the contents of root are less than the contents of the
     * new node
     */
    } else if(root_->contents() < insertNode->contents())
    {
        /**
         * Checks if the right child of root is null and inserts the node
         * there if it is, else it calls the insert function with the value
         * and the contents of the roots right child
         */
        if(root_->right_child() == NULL){
            //root_->set_right_child(insertNode);
            size_ = size_ + 1;
        } else 
        {
            Insert(value, node->right_child());
        }
    }
    return true;
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
    if (root_ != NULL)
    {
        /**
         * Checks if both childs of the root are null and deletes the root
         * if they are
         */
        if (root_->left_child() == NULL && root_->right_child() == NULL)
        {
            delete root_;
            root_ = NULL;
        /**
         * If either of the roots child nodes has contents then it calls the
         * Clear function again on the current node in the tree being looked at
         */
        } else
        {
            if (root_->left_child())
            {
            Clear(root_->left_child());
            } else
            if (root_->right_child())
            {
                Clear(root_->right_child());
            }
        }
    size_ = 0;
    root_ = NULL;
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
    string outputString = "";
    
    if (root_ == NULL)
    {
    return outputString;
    }
    else 
    {
        if (root_->left_child() && root_->right_child())
        {
            InOrder(root_->left_child());
            InOrder(root_->right_child());
        }
        else
        if (root_->left_child() && !root_->right_child())
        {
            InOrder(root_->left_child());
        }
        else
        if (!root_->left_child() && root_->right_child())
        {
            InOrder(root_->right_child());
        }
        outputString += root_->contents() + " ";
    return outputString;
    }
    //return ordered;
}