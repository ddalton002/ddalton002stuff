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
 * calls private function Remove(int, root)
 */
bool BSTree::Remove(int num)
{
    return Remove(num, root_);
}

/**
 * calls private function FindMin(root)
 */
int BSTree::FindMin()
{
    return FindMin(root_);
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

/**
 * traverses the tree and removes the node containing the target
 * integer if present and returns true
 * return false if target integer is not in tree (or the tree is empty)
 */
bool BSTree::Remove(int value, BSTNode*& node)
{
    /**
     * Creates an iterator to traverse the tree
     */
    BSTNode* iterator = node;
    /**
     * Checks if the current node is null and returns false if it is
     */
    if (node == NULL)
    return false;
    else
    {
        /**
         * Checks if the contents of the node are greater than the value being
         * removed, calls the itself with the current node and value
         * being looked for if it is
         */
        if (value < node->contents())
        Remove(value, node->left_child());
        
        /**
         * Checks if the contents of the node are less than the value being
         * removed, calls the itself with the current node and value
         * being looked for if it is
         */
        else if (value > node->contents())
        Remove(value, node->right_child());
        
        /**
         * Checks if the contents of the node are equal to the value being
         * looked for
         */
        else if (node ->contents() == value)
        {
            /**
             * If the node has no left or right children then it sets the node
             * equal to null, deletes the iterator and reduces size_
             */
            if (!node->left_child() && !node->right_child())
            {
                node = NULL;
                delete iterator;
                size_ = size_ - 1;
            /**
             * Checks if the node doesn't have a left child.  If it doesn't
             * then it replaces the node with the nodes right child, deletes
             * the iterator and reduces size_
             */
            } else if (!node->left_child())
            {
                node = node->right_child();
                delete iterator;
                size_ = size_ - 1;
            /**
             * Checks if the node doesn't have a right child.  If it doesn't
             * then it replaces the node with the nodes left child, deletes
             * the iterator and reduces size_
             */
            } else if (!node->right_child())
            {
                node = node->left_child();
                delete iterator;
                size_ = size_ - 1;
                
            /**
             * Checks if the node has left and right children
             */
            } else 
            {
                /**
                 * Sets the node equal to the lowest value in the right side
                 * of the tree, then calls the remove function on the
                 * right side of the tree with the contents of the node
                 * and the nodes right child to remove the original lowest
                 * value node
                 */
                node->set_contents(FindMin(node->right_child()));
                Remove(node->contents(), node->right_child());
            }
            return true;
        }
    }
}

/**
 * returns the value of the smallest node in the tree
 * helper function for private Remove()
 */
int BSTree::FindMin(BSTNode* node) const
{
     /**
      * Checks if the node is empty
      */
     if (node == NULL)
     return 0;
     /**
      * Loops through the left side of the tree until it finds the lowest value
      * in the tree by location the left child where it's left child is 
      * equal to null
      */
     while (node->left_child() != NULL)
     node = node->left_child();
     /**
      * Returns the contents of that node
      */
     return node->contents();
}