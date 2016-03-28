/*
Declare and implement a class that provides the following interface EXACTLY.
You will create 2 new files, sl_node.h and sl_node.cpp

Class Name: SLNode

Private Members:

  SLNode* next_node_
  --points to the next node in a singly-linked list
  int contents_
  --stores the data contents of a SLNode

Public Members:

  Default Constructor
  --sets next_node_ to NULL
  --sets contents_ to 0

  Overloaded Constructor
  --int parameter assigned to contents_
  --sets next_node to NULL
  
  Destructor
  --does nothing
  
  void set_contents(int)
  --mutator for contents_
  int contents() const
  --accessor for contents_
  
  void set_next_node(SLNode*)
  --mutator for next_node_
  SLNode* next_node() const
  --accessor for next_node_
*/