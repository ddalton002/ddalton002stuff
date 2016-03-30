/*
 * Name        : sl_list.cpp
 * Author      : David Dalton
 * Description : Node list lab.
 */
 
#include "sl_list.h"

/*
  Default Constructor
  --sets head_ to NULL
  --sets size_ to 0
  */
  SLList::SLList() 
  {
    head_ = NULL;
    size_ = 0;
  }
  /*
  Destructor
  --calls Clear()
  */
  SLList::~SLList() 
  {
    SLList::Clear();
  }
  /*
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
  }
  /*
  void RemoveHead()
  --removes the head node from the list,
    or does nothing if the list is empty
  */
  void SLList::RemoveHead() 
  {
    if(head_ != NULL)
    {
      SLNode* temp_node = head_;
      head_ = head_->next_node();
      delete temp_node;
      temp_node = NULL;
      size_ = size_ - 1;
    }
  }
  /*
  void Clear()
  --clears the entire contents of the list,
    freeing all memory associated with all nodes
  */
  void SLList::Clear() 
  {
    while(head_ != NULL)
    {
      RemoveHead();
    }
    delete head_;
    head_ = NULL;
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