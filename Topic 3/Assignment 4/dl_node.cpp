/*
 * Name        : sl_node.cpp
 * Author      : David Dalton
 * Description : Node list lab.
 */

#include "dl_node.h"

/**
 * initialize contents to zero, next and previous to NULL
 */
 DLNode::DLNode() 
 {
    contents_ = 0;
    previous_node_ = NULL;
    next_node_ = NULL;
 }
/**
 * initialize contents to newContents, next and previous to NULL
 */
 DLNode::DLNode(int newContents) 
 {
    contents_ = newContents;
    previous_node_ = NULL;
    next_node_ = NULL;
 }
/**
 * nothing to be done
 */
 DLNode::~DLNode() 
 {

 }
/**
 * 
 */
 void DLNode::setContents(int newContents) 
 {
    contents_ = newContents;
 }
/**
 * 
 */
 void DLNode::setNext(DLNode* newNext) 
 {
    next_node_ = newNext;
 }
/**
 * 
 */
 void DLNode::setPrevious(DLNode* newPrevious) 
 {
    previous_node_ = newPrevious;
 }
/**
 * 
 */
 int DLNode::getContents() const 
 {
    return contents_;
 }
/**
 * 
 */
 DLNode* DLNode::getNext() const 
 {
    return next_node_;
 }
/**
 * 
 */
 DLNode* DLNode::getPrevious() const 
 {
    return previous_node_;
 }