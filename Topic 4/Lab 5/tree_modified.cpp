/*
 * Name        : bs_tree.h
 * Author      : 
 * Description : 
 */
 #include "bs_tree.h"




/**
 * creates a new BSTNode, Inserts it into the tree, and returns true
 * if the integer is already in the tree, does not Insert, and returns false
 */
bool BSTree::Insert(int contents, BSTNode*& root)
{
    BSTNode* newNode = new BSTNode(contents);
    if (root == NULL)
    {
        root = newNode;
        size_ += 1;
        return true;
    } 
    else if (newNode->contents() < root->contents())
    {
        // if (root->left_child() == NULL)
        // {
        // root->set_left_child(newNode);
        // size_ += 1;
        // }
        // else
        Insert(contents, root->left_child());
    }
    else if (newNode->contents() > root->contents())
    {
        Insert(contents, root->right_child());
        
    }else
    return false;
}

/**
 * clears the entire contents of the tree,
 * freeing all memory associated with all nodes
 */
void BSTree::Clear(BSTNode*& root)
{
    if (root != NULL)
    {
        if (root->left_child() == NULL && root->right_child() == NULL)
        {
            delete root;
            root = NULL;
        } else
        {
            if (root->left_child())
            {
            Clear(root->left_child());
            }
            if (root->right_child())
            {
                Clear(root->right_child());
            }
        }
    size_ -= 1;
    root = NULL;
    }
}

/**
 * creates a string of the data in all nodes in the tree, in ascending order
 * separate by spaces (there should be a space after the last output value)
 */
string BSTree::InOrder(BSTNode* root)
{
    stringstream ordered;
    if (root == NULL)
    {
        ordered << "";
    }
    else 
    {
        ordered<<InOrder(root->left_child());
        ordered << root->contents() << " ";
        ordered<<InOrder(root->right_child());
    }
    return ordered.str();
}

/**
 * traverses the tree and removes the node containing the target
 * integer if present and returns true
 * return false if target integer is not in tree (or the tree is empty)
 */
bool BSTree::Remove(int num, BSTNode*& root)
{
    BSTNode* temp = root;
    if (root == NULL)
    return false;
    else
    {
        /**
         * checks if num is < node contents and calls remove 
         * on left child if it is
         */
        if (num < root->contents())
        Remove(num, root->left_child());
        
        /**
         * checks if num is > node contents and calls remove 
         * on right child if it is
         */
        else if (num > root->contents())
        Remove(num, root->right_child());
        
        /**
         * performs removal if node contents == num
         */
        else if (root ->contents() == num)
        {
            //case no children
            if (!root->left_child() && !root->right_child())
            {
                root = NULL;
                delete temp;
                size_ -=1;
            
            // case only right child    
            } else if (!root->left_child())
            {
                root = root->right_child();
                delete temp;
                size_ -= 1;
            
            //case only left child    
            } else if (!root->right_child())
            {
                root = root->left_child();
                delete temp;
                size_ -= 1;
                
            //case two children    
            } else 
            {
                /**
                 * sets node contents to the min value in
                 * its right subtree
                 */
                root->set_contents(FindMin(root->right_child()));
                /**
                 * performs remove on the right subtree 
                 * to remove the duplicate
                 */
                Remove(root->contents(), root->right_child());
            }
            return true;
        }
    }
}

/**
 * returns the value of the smallest node in the tree
 * helper function for private Remove()
 */
int BSTree::FindMin(BSTNode* root) const
{
     //Check if tree is empty
     if (root == NULL)
     return 0;
     //turn left
     while (root->left_child() != NULL)
     root = root->left_child();
     //bring it home
     return root->contents();
}

/**
 * Default constructor
 * sets root_ to NULL
 * sets size_ to 0
 */
BSTree::BSTree()
{
    root_ = NULL;
    size_ = 0;
}

/**
 * destructor
 * calls Clear()
 */
BSTree::~BSTree()
{
    Clear();
}

/**
 * calls private function Insert(int, root)
 */
bool BSTree::Insert(int contents)
{
    return Insert(contents, root_);
}

/**
 * returns value returned by private function Remove(int, root)
 */
bool BSTree::Remove(int num)
{
    return Remove(num, root_);
}

/**
 * if the tree is empty return 0
 * otherwise return the value returned by private function FindMin(root)
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