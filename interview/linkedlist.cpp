/*
 * =====================================================================================
 *
 *       Filename:  linkedlist.cpp
 *
 *    Description:  implementation for linkedlist
 *
 *        Version:  1.0
 *        Created:  02/03/2012 13:51:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  MonkeyTaolun 
 *        Company:  
 *
 * =====================================================================================
 */

#include "linkdedlist.hpp"
#include <iostream>
template  <class T>
LinkedNode::LinkedNode(T element) : element(element), next(NULL) {}
template  <class T>
LinkedNode::LinkedNode() : next(NULL) {}

template  <class T>
void  LinkedList::put(const T element) {
  if(NULL != head) {
    head  = new LinkedNode(element);
  }
  else {
    LinkedNode  * refPointer = head;
    while(NULL  !=  refPointer->next){
      refPointer  = refPointer->next;
    }
    refPointer->next  = new LinkedList(element);
  }
}

template  <class T>
T *   LinkedList::get(const size_t index){
  LinkedNode <T> * refPointer = this->head;
  while(NULL  !=  refPointer && index-- != 0) {
    refPointer  = refPointer->next;
  }
  if(index < 0){
    return refPointer;
  }
  return NULL;
}

template  <class T>
void  LinkedList::traverse()  const {
  LinkedNode <T> * refPointer = this->head;
  while(NULL != refPointer) {
    std::cout << refPointer->element << " ";
    refPointer  = refPointer->next;
  }
}

template  <class T>
void  removeNext(T * const refPointer) {
  if(NULL == refPointer || NULL == refPointer->next) return;
  T * tempPointer = refPointer->next->next;
  delete refPointer->next;
  refPointer->next  = tempPointer;
}

template  <class T>
bool  LinkedList::remove(const T element) {
  if(NULL ==  this->head) return false;
  T * refPointer  = NULL;
  if(element  ==  this->head) {
    refPointer  = this->head->next;
    delete this->head;
    this->head  = refPointer;
    return;
  }
  refPointer  = this->head;
  while(NULL != refPointer->next) {
    if (element ==  refPointer->next->element) {
      this->removeNext(element);
      return true;
    }
  }
  return false;
}
template  <class T>
size_t  LinkedList::removeAll(const T element) {

  if (NULL == this->head) {
    return 0;
  }
  size_t  counter = 0;
  T * refPointer = this->head;
  // T * refPointer2 = NULL;
  while(NULL != refPointer && element == refPointer->element) {
    counter++;
    this->head = refPointer->next;
    delete refPointer;
    refPointer = this->head;
  }
  this->head  = refPointer;
  while(NULL  !=  refPointer->next) {
    if( refPointer->next->element == element) {
      this->removeNext(refPointer);
      counter++;
    }
    refPointer = refPointer->next;
  }
  /*  
  refPointer2 = refPointer1->next;
  while(NULL != refPointer2) {
    if(element  ==  refPointer2->element) {
      counter++;
      refPointer1->next = refPointer2->next;
      delete refPointer2;
      refPointer2 = refPointer1->next;
    }
    else {
      refPointer1 = refPointer2;
      refPointer2 = refPointer1->next;
    }
  }
  */
  return counter;
}
