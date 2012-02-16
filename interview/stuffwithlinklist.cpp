#include <iostream>
template <class T>
struct Node {
  T       element;
  Node  * next;
};
template <class T>
Node<T> * getLastNth(Node<T>* head, size_t n) {
  if(n < 1) return NULL;
  Node<T> * p1  = head;
  size_t  total = 0;
  while(NULL!=p1) total++;
  if(total < n) return NULL;
  p1  = head;
  size_t  counter = total - n;
  while(counter > 0) {
    p1  = p1->next;
  }
  return p1->next;
} 
/*
template <class T>
Node<T> * getLastNth2(Node<T>* node, size_t current, size_t lastn){
  if(NULL ==  node) {
    return 
  }
}
*/

template  <class T>
Node<T> * getLastNth2(Node<T>* node, size_t n) {
  if(n < 1) return NULL;
  Node  * p1  = head;
  Node  * p2  = head;
  while(NULL  !=  p1 && n-- > 0) {
    p1  = p1->next;
  }
  if ( n > 0) return NULL;
  while(NULL  !=  p1) {
    p1  = p1->next;
    p2  = p2->next;
  }
  return p2;
}

template  <class T>
void reverse_list(Node<T>* & head) {
  Node<T> * remain  = head->next;
  head->next  = NULL;
  while(NULL!=remain) {
    Node * temp = remain;
    remain      = remain->next;
    temp->next  = head;
    head        = temp;
  }
}