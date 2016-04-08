/*
 * Name        : dl_list.cpp
 * Author      : David Dalton
 * Description : Node list lab.
 */

#include "dl_list.h"

/**
 * initialize count to zero, head and tail to NULL
 */
 DLList::DLList() 
 {
    count_ = 0;
    head_ = NULL;
    tail_ = NULL;
 }
/**
 * call clear function
 */
 DLList::~DLList() 
 {
    clear();
 }
/**
 * return count
 */
 unsigned int DLList::getSize() const 
 {
    return count_;
 }
/**
 * create new DLNode with newContents and attach at head
 */
 void DLList::pushFront(int newContents) 
 {
     /**
     * Creates a new node with the specified contents, then inserts it at the
     * start of the list.  Increases the size variable and points tail to 
     * head if it was currently null
     */
    DLNode* new_node = new DLNode(newContents);
    new_node->setNext(head_);
    new_node->setPrevious(tail_);
    head_ = new_node;
    count_ = count_ + 1;
    if (tail_ == NULL)
    {
      tail_ = head_;
    }
 }
/**
 * create new DLNode with newContents and attach at tail
 */
 void DLList::pushBack(int newContents) 
 {
    /**
     * Checks if the list is empty, if so calls the InsertHead() function
     */
    if(head_ != NULL)
    {
      /**
       * Creates a new node of the specified value and a iterator node, then
       * sets the iterator node to head_
       */
      DLNode* temp_node, *newNode = new DLNode(newContents);
      temp_node = head_;
      /**
       * Loops through the list to check if the next node is null, if not it
       * iterates to the next node
       */
      while(temp_node->getNext() != NULL)
      {
        temp_node = temp_node->getNext();
      }
      /**
       * Inserts the node at the end of the list, points the tail to it and
       * increases the size variable by 1
       */
      temp_node->setNext(newNode);
      //head_->setPrevious(newNode);
      tail_ = newNode;
      count_ = count_ + 1;
    } else 
    {
      pushFront(newContents);
    }
 }
/**
 * create new DLNode with newContents and insert in ascending (based on 
 * newContents) order
 */
 void DLList::insert(int newContents) 
 {
    /**
     * Checks to see if head_ is null or if the contents of head_ are greater
     * then the parameter being inserted. If it is then calls the 
     * pushFront() function, otherwise continues to next check
     */
    if(head_ == NULL || head_->getContents() > newContents)
    {
        pushFront(newContents);
      /**
       * Checks if the contents of tail_ are less then the parameter being
       * inserted.  If so, calls pushBack() function, otherwise continues
       * to next check
       */
    } else if (tail_->getContents() < newContents)
    {
      pushBack(newContents);
      /**
       * Inserts the parameter into the correct location in the list
       */
    } else 
    {
      DLNode* iterator;
      iterator = head_;
      /**
       * Checks whether the contents of the next node is less then the parameter
       * and that the next node is not the tail.  If they are not, then it 
       * advances the iterator to the next node in the list
       */
      while(newContents > iterator->getNext()->getContents() && iterator->getNext() != tail_)
      {
        iterator = iterator->getNext();
      }
      /**
       * Checks if the iterator is located at the tail
       */
      if(iterator != tail_)
      {
        /**
         * If the iterator is not located at the tail, it creates a new node
         * and inserts it at the iterators current location, then increases
         * the size variable by 1
         */
        DLNode* new_node = new DLNode(newContents);
        new_node->setNext(iterator->getNext());
        //new_node->setPrevious(iterator);
        iterator->setNext(new_node);
        count_ = count_ + 1;
      } else
      {
        /**
         * If the iterator is located at the tail, then calls the InsertTail()
         * function
         */
        pushBack(newContents);
      }
    }
 }
/**
 * return the value of the contents of the head node; throw an exception 
 * (throw "LIST EMPTY") if the list is empty
 */
 int DLList::getFront() const 
 {
    if(count_ != 0)
    {
        return head_->getContents();
    }
    throw "LIST EMPTY";
 }
/**
 * return the value of the contents of the tail node; throw an exception 
 * (throw "LIST EMPTY") if the list is empty
 */
 int DLList::getBack() const 
 {
    if(count_ != 0)
    {
        return tail_->getContents();
    }
    throw "LIST EMPTY";
 }
/**
 * return true if target is in list, else return false
 */
 bool DLList::get(int target) const 
 {
    /**
     * Checks if the head is null and returns false if it is
     */
    if(head_ == NULL)
    {
      return false;
    /**
     * Checks if the contents of head_ are equal to the parameter and returns true if it is
     */
    } else if(head_->getContents() == target)
    {
      return true;
    /**
     * Checks if the contents of tail_ are equal to the parameter and returns true if it is
     */
    } else if(tail_->getContents() == target)
    {
      return true;
    /**
     * checks if the list contains only two nodes, if it does not then
     * it checks for the specified parameter, otherwise it returns false
     */
    } else if(head_->getNext() != tail_)
    {
      DLNode* iterator = head_->getNext();
      /**
       * Loops through the node list checking the contents of the current
       * node to the parameter and if the next node is the tail, if neither
       * statement is true then it iterates to the next node
       */
      while(iterator->getContents() != target && iterator->getNext() != tail_)
      {
        iterator = iterator->getNext();
      }
      /**
       * Checks if the contents of the current node are equal to the parameter
       * and returns true, if not then returns false
       */
      if(iterator->getContents() == target)
      {
        return true;
      } else
      {
        return false;
      }
    } else
    {
      return false;
    }
 }
/**
 * remove current head node; do nothing if list is empty
 */
 void DLList::popFront() 
 {
    /**
     * Checks if the list is empty
     */
    if(head_ != NULL)
    {
      /**
       * Checks if head_ is equal to tail_ and sets tail_ to null if it is
       */
      if(head_ == tail_)
      {
        tail_ = NULL;
      }
      /**
       * Creates a temporary node and points it to head, then points head to 
       * the next node
       */
      DLNode* temp_node = head_;
      head_ = head_->getNext();
     // head_->setPrevious(tail_);
      // Delets the temporary node and sets it to null, then decreases size by 1
      delete temp_node;
      temp_node = NULL;
      count_ = count_ - 1;
    }
 }
/**
 * remove current tail node; do nothing if list is empty
 */
 void DLList::popBack() 
 {
    /**
	   * Checks if list is empty
	   */
	  if(head_ != NULL)
    {
      /**
       * Checks if head_ is equal to tail_ and calls the RemoveHead() function
       * if it is
       */
      if(head_ != tail_)
      {
      /**
       * Creates a temporary node and points it to head
       */
        DLNode* temp_node = head_;
        /**
         * Loops through the list and checks if the next node is the tail,
         * if it is not then it iterates to the next node
         */
        while(temp_node->getNext() != tail_)
        {
          temp_node = temp_node->getNext();
        }
        /**
         * Sets the last node in the list to null and deletes the tail,
         * then sets tail equal to the temp node and decreases the size 
         * variable
         */
        temp_node->setNext(NULL);
        delete tail_;
        tail_ = temp_node;
        count_ = count_ - 1;
      } else 
      {
        popFront();
      }
    }
 }
/**
 * remove the first instance of a DLNode containing target; do nothing if 
 * target is not found
 */
 bool DLList::removeFirst(int target) 
 {
    /**
     * Checks if the head is null and returns false if it is
     */
    if(head_ == NULL)
    {
      return false;
    /**
     * Checks if the contents of head_ are equal to the parameter, then
     * calls the popBack() function and returns true if it is
     */
    } else if(head_->getContents() == target)
    {
      popBack();
      return true;
    /**
     * Checks if the contents of tail_ are equal to the parameter, then
     * calls the popBack() function and returns true if it is
     */
    } else if(tail_->getContents() == target)
    {
      popBack();
      return true;
    /**
     * checks if the list contains only two nodes, if it does not then
     * it checks for the specified parameter, otherwise it returns false
     */
    } else if(head_->getNext() != tail_)
    {
      DLNode* iterator = head_->getNext();
      DLNode* temp_node = head_;
      /**
       * Loops through the node list checking the contents of the current
       * node to the parameter and if the next node is the tail, if neither
       * statement is true then it iterates to the next node
       */
      while(iterator->getContents() != target && iterator->getNext() != tail_)
      {
        temp_node = iterator;
        iterator = iterator->getNext();
      }
      /**
       * Checks if the contents of the current node are equal to the parameter,
       * if not then returns false
       */
      if(iterator->getContents() == target)
      {
        /**
         * Sets the placeholder node to the node that the iterator is pointing
         * to then deletes the iterator node, reduces the size variable
         * then returns true
         */
        temp_node->setNext(iterator->getNext());
        delete iterator;
        iterator = NULL;
        count_ = count_ - 1;
        return true;
      } else
      {
        return false;
      }
    } else
    {
      return false;
    }
 }
/**
 * remove all instances of DLNode containing target; do nothing if target 
 * is not found
 */
 bool DLList::removeAll(int target) 
 {
    /**
     * Checks if the head is null and returns false if it is
     */
    if(head_ == NULL)
    {
      return false;
    /**
     * Checks if the contents of head_ are equal to the parameter, then
     * calls the popBack() function and returns true if it is
     */
    } else if(head_->getContents() == target)
    {
      popBack();
    /**
     * Checks if the contents of tail_ are equal to the parameter, then
     * calls the popBack() function and returns true if it is
     */
    } else if(tail_->getContents() == target)
    {
      popBack();
    /**
     * checks if the list contains only two nodes, if it does not then
     * it checks for the specified parameter, otherwise it returns false
     */
    } else if(head_->getNext() != tail_)
    {
      DLNode* iterator = head_->getNext();
      DLNode* temp_node = head_;
      /**
       * Loops through the node list checking the contents of the current
       * node to the parameter and if the next node is the tail, if neither
       * statement is true then it iterates to the next node
       */
      while(iterator->getContents() != target && iterator->getNext() != tail_)
      {
        temp_node = iterator;
        iterator = iterator->getNext();
      }
      /**
       * Checks if the contents of the current node are equal to the parameter,
       * if not then returns false
       */
      if(iterator->getContents() == target)
      {
        /**
         * Sets the placeholder node to the node that the iterator is pointing
         * to then deletes the iterator node, reduces the size variable
         * then returns true
         */
        temp_node->setNext(iterator->getNext());
        delete iterator;
        iterator = NULL;
        count_ = count_ - 1;
      } else
      {
        return false;
      }
    } else
    {
      return false;
    }
    return true;
 }
/**
 * clear all nodes from list, reset count to zero, set head and tail to NULL
 */
 void DLList::clear() 
 {
    while(head_ != NULL)
    {
      popFront();
    }
    delete head_;
    head_ = NULL;
    tail_ = NULL;
 }
/**
 * display the contents of each node in the list, formatted per the 
 * program specification ("NUM1,NUM2,NUM3,...,NUMX"), to the output stream 
 * out
 */
 ostream& operator <<(ostream &out, const DLList &src) 
 {
    /**
     * Checks if the node list is empty and returns an empty string if it is
     */
    DLNode* temp_node = src.head_;
    if(temp_node != NULL)
    {
      /**
       * Using a while loop, checks every node if it is null, if it is not
       * then it adds its contents to a stringstream and then checks if the
       * next node is null, if not adds a separator string
       */
      while(temp_node != NULL)
      {
        out << temp_node->getContents();
        if(temp_node->getNext() != NULL)
        {
          out << ", ";
        }
        temp_node = temp_node->getNext();
      }
      //return out;
    } else {
        out << "";
    }
    // Returns the stringstream
    return out;
 }