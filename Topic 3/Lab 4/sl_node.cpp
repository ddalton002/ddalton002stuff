/*
 * Name        : sl_node.cpp
 * Author      : David Dalton
 * Description : Node lab.
 */
 
#include "sl_node.h"

/*
   *Default Constructor
   */
   SLNode::SLNode()
   {
       next_node_ = NULL;
       contents_ = 0;
   }
  /*
   *Overloaded Constructor
   */
   SLNode::SLNode(int contents) 
   {
       next_node_ = NULL;
       contents_ = contents;
   }
  /*
   *Destructor
   */
   SLNode::~SLNode() 
   {
       
   }
  /*
   *Mutator for contents_
   */
   void SLNode::set_contents(int contents) 
   {
       contents_ = contents;
   }
   /*
   *Accessor for contents_
   */
   int SLNode::contents() 
   {
       return contents_;
   }
  /*
   *void set_next_node(SLNode*)
   *--mutator for next_node_
   */
   void SLNode::set_next_node(SLNode* next_node) 
   {
       next_node_ = next_node;
   }
   /*
   *SLNode* next_node() const
   *--accessor for next_node_
   */
   SLNode* SLNode::next_node() const
   {
       return next_node_;
   }