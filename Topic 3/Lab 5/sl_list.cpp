/*
 * Name        : sl_list.cpp
 * Author      : David Dalton
 * Description : Node list lab.
 */
 
#include "sl_list.h"
 /*
  Default Constructor
  --sets head_ to NULL
  --sets tail_ to NULL
  --sets size_ to 0
  */
  SLList::SLList() 
  {
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
  }
  /*
  Destructor
  --calls Clear()
  */
  SLList::~SLList() 
  {
    Clear();
  }
  /*
  --clears the entire contents of the list,
    freeing all memory associated with all nodes
    (*NEW*) - sets tail_ to NULL
  */
  void SLList::Clear() 
  {
    while(head_ != NULL)
    {
      RemoveHead();
    }
    delete head_;
    head_ = NULL;
    tail_ = NULL;
  }
  /*
  --creates a new SLNode with the contents of the parameter and
    inserts it into the correct position in the list. The list
    will be sorted with the lowest values in the front (head) and the
    largest values in the back (tail).
   */
  void SLList::Insert(int insert) 
  {
    /**
     * Checks to see if head_ is null or if the contents of head_ are greater
     * then the parameter being inserted. If it is then calls the 
     * InsertHead() function, otherwise continues to next check
     */
    if(head_ == NULL || head_->contents() > insert)
    {
      InsertHead(insert);
      /**
       * Checks if the contents of tail_ are less then the parameter being
       * inserted.  If so, calls InsertTail() function, otherwise continues
       * to next check
       */
    } else if (tail_->contents() < insert)
    {
      InsertTail(insert);
      /**
       * Inserts the parameter into the correct location in the list
       */
    } else 
    {
      SLNode* iterator;
      iterator = head_;
      /**
       * Checks whether the contents of the next node is less then the parameter
       * and that the next node is not the tail.  If they are not, then it 
       * advances the iterator to the next node in the list
       */
      while(insert > iterator->next_node()->contents() && iterator->next_node() != tail_)
      {
        iterator = iterator->next_node();
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
        SLNode* new_node = new SLNode(insert);
        new_node->set_next_node(iterator->next_node());
        iterator->set_next_node(new_node);
        size_ = size_ + 1;
      } else
      {
        /**
         * If the iterator is located at the tail, then calls the InsertTail()
         * function
         */
        InsertTail(insert);
      }
    }
  }
  /*
  --remove the first occurence of the supplied parameter
    found as the data of a node. Return true on successful
    removal or false if the list is empty or if the value
    is not found.
   */
  bool SLList::RemoveFirstOccurence(int parameter) 
  { 
    /**
     * Checks if the head is null and returns false if it is
     */
    if(head_ == NULL)
    {
      return false;
    /**
     * Checks if the contents of head_ are equal to the parameter, then
     * calls the RemoveHead() function and returns true if it is
     */
    } else if(head_->contents() == parameter)
    {
      RemoveHead();
      return true;
    /**
     * Checks if the contents of tail_ are equal to the parameter, then
     * calls the RemoveTail() function and returns true if it is
     */
    } else if(tail_->contents() == parameter)
    {
      RemoveTail();
      return true;
    /**
     * checks if the list contains only two nodes, if it does not then
     * it checks for the specified parameter, otherwise it returns false
     */
    } else if(head_->next_node() != tail_)
    {
      SLNode* iterator = head_->next_node();
      SLNode* temp_node = head_;
      /**
       * Loops through the node list checking the contents of the current
       * node to the parameter and if the next node is the tail, if neither
       * statement is true then it iterates to the next node
       */
      while(iterator->contents() != parameter && iterator->next_node() != tail_)
      {
        temp_node = iterator;
        iterator = iterator->next_node();
      }
      /**
       * Checks if the contents of the current node are equal to the parameter,
       * if not then returns false
       */
      if(iterator->contents() == parameter)
      {
        /**
         * Sets the placeholder node to the node that the iterator is pointing
         * to then deletes the iterator node, reduces the size variable
         * then returns true
         */
        temp_node->set_next_node(iterator->next_node());
        delete iterator;
        iterator = NULL;
        size_ = size_ - 1;
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
  /*
	-- Returns the contents of the head node
     (The node head_ is pointing to)
     Returns 0 if the list is empty
    */
  int SLList::GetHead() const 
  {
    if(size_ != 0)
    {
      return head_->contents();
    } else 
    {
      return 0;
    }
    
  }
  /*
  -- Returns the contents of the tail node
     (The node tail_ is pointing to)
     Returns 0 if the list is empty
    */
  int SLList::GetTail() const 
  {
    if(size_ != 0)
    {
      return tail_->contents();
    } else 
    {
      return 0;
    }
  }
  /*
  unsigned int size() const
  --accessor for size_
  */
  unsigned int SLList::size() const 
  {
    return size_;
  }
  /*
  string ToString() const
  --returns a string representation of the contents
    of all nodes in the list, in the format
    NUM1, NUM2, ..., LASTNUM
    returns the empty string on an empty list (i.e. returns "")
    */
  string SLList::ToString() 
  {
    /**
     * Checks if the node list is empty and returns an empty string if it is
     */
    if(head_ != NULL)
    {
      stringstream stream;
      SLNode* temp_node = head_;
      /**
       * Using a while loop, checks every node if it is null, if it is not
       * then it adds its contents to a stringstream and then checks if the
       * next node is null, if not adds a separator string
       */
      while(temp_node != NULL)
      {
        stream << temp_node->contents();
        if(temp_node->next_node() != NULL)
        {
          stream << ", ";
        }
        temp_node = temp_node->next_node();
      }
      // Returns the stringstream
      return stream.str();
    } else {
      return "";
    }
  }
  /*
  void InsertHead(int)

	- Handle tail_ when the first node in the list is added
  void InsertHead(int)
  --creates a new dynamic SLNode with the contents of 
    the parameter and attaches as the new head of the list
  */
  void SLList::InsertHead(int insert) 
  {
    /**
     * Creates a new node with the specified contents, then inserts it at the
     * start of the list.  Increases the size variable and points tail to 
     * head if it was currently null
     */
    SLNode* new_node = new SLNode(insert);
    new_node->set_next_node(head_);
    head_ = new_node;
    size_ = size_ + 1;
    if (tail_ == NULL)
    {
      tail_ = head_;
    }
  }
  /*
	--creates a new dynamic SLNode with the contents of 
		the parameter and attaches as the last node (tail) of the list
	 */
  void SLList::InsertTail(int insert) 
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
      SLNode* temp_node, *newNode = new SLNode(insert);
      temp_node = head_;
      /**
       * Loops through the list to check if the next node is null, if not it
       * iterates to the next node
       */
      while(temp_node->next_node() != NULL)
      {
        temp_node = temp_node->next_node();
      }
      /**
       * Inserts the node at the end of the list, points the tail to it and
       * increases the size variable by 1
       */
      temp_node->set_next_node(newNode);
      tail_ = newNode;
      size_ = size_ + 1;
    } else 
    {
      InsertHead(insert);
    }
  }
  /*
  void RemoveHead()
  --removes the head node from the list,
    or does nothing if the list is empty
	  !!Handle tail_ when the last remaining node in the list is removed
  */
  void SLList::RemoveHead() 
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
      SLNode* temp_node = head_;
      head_ = head_->next_node();
      // Delets the temporary node and sets it to null, then decreases size by 1
      delete temp_node;
      temp_node = NULL;
      size_ = size_ - 1;
    }
  }
  /*
  --removes the last node (tail) from the list,
	  or does nothing if the list is empty
	 */
	void SLList::RemoveTail()
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
        SLNode* temp_node = head_;
        /**
         * Loops through the list and checks if the next node is the tail,
         * if it is not then it iterates to the next node
         */
        while(temp_node->next_node() != tail_)
        {
          temp_node = temp_node->next_node();
        }
        /**
         * Sets the last node in the list to null and deletes the tail,
         * then sets tail equal to the temp node and decreases the size 
         * variable
         */
        temp_node->set_next_node(NULL);
        delete tail_;
        tail_ = temp_node;
        size_ = size_ - 1;
      } else 
      {
        RemoveHead();
      }
    }
	}