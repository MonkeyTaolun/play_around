// 
//  about_linkedList.cpp
//  Interview stuffs
//  
//  Created by Taolun Chai on 2012-02-13.
//  Copyright 2012 MonkeyTaolun. All rights reserved.
// 

#include <iostream>
// just assume we use int
struct Node {
  int element;
  Node * next;
};

Node * get_last_nth(const Node * const head, int n) {
  Node * p1 = head;
  Node * p2 = head;
  while(NULL!=  p && n-->0) {
    p1  = p1->next;
  }
  if (n > 0) return NULL;
  while(NULL  !=  p1) {
    p1  = p1->next;
    p2  = p2->next;
  }
  return p2;
}

void reverse(Node *& head) {
  if ( NULL == head ) return;
  Node  * remain  = head->next;
  head->next  = NULL;
  
  while(remain){
    Node * tmp  = remain->next;
    remain->next  = head;
    head = remain;
    remain  = tmp;
  }
}

