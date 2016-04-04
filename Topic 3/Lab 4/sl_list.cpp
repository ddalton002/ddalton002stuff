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
  void InsertHead(int) (*MODIFY*)

		(*NEW*) - Handle tail_ when the first node in the list is added
  void InsertHead(int)
  --creates a new dynamic SLNode with the contents of 
    the parameter and attaches as the new head of the list
  */
  void SLList::InsertHead(int insert) 
  {
    SLNode* new_node = new SLNode(insert);
    new_node->set_next_node(head_);
    head_ = new_node;
    size_ = size_ + 1;
    /*
    if(tail_ == 1)
    {
      tail_ = head_;
    }*/
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
    if(head_ != NULL)
    {
      SLNode* new_node, *newNode = new SLNode(insert);
      new_node = head_;
      while(new_node->next_node() != NULL)
      {
        new_node = new_node->next_node();
      }
      new_node->set_next_node(newNode);
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
    if(head_ != NULL)
    {
      if(head_ == tail_)
      {
        tail_ = NULL;
      }
      SLNode* temp_node = head_;
      head_ = head_->next_node();
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
	  if(head_ != NULL)
    {
      if(head_ != tail_)
      {
        SLNode* temp_node = head_;
        while(temp_node->next_node() != tail_)
        {
          temp_node = temp_node->next_node();
        }
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
	-- Returns the contents of the head node
     (The node head_ is pointing to)
     Returns 0 if the list is empty
    */
  int SLList::GetHead() const 
  {
    //if(head_ != NULL)
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
    //if(head_ != NULL)
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
    if(head_ != NULL)
    {
      stringstream stream;
      SLNode* temp_node = head_;
      while(temp_node != NULL)
      {
        stream << temp_node->contents();
        if(temp_node->next_node() != NULL)
        {
          stream << ", ";
        }
        temp_node = temp_node->next_node();
      }
      return stream.str();
    } else {
      return "";
    }
  }