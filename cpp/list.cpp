#include <iostream>
#include <stdlib.h>
namespace {

template <class T>
struct ListNode{
  T   item;
  ListNode <T> * next;
};

template <class T>
ListNode<T> * search_list(ListNode<T> * l, const T item){
  if(NULL == l)  return NULL;

  if(item == l->item) return l;

  return search_list(l->next, item);
}

template <class T>
void insert_list(ListNode <T> **l, const T item){
  ListNode <T> * p;

  p = new ListNode<T> ();

  p->item = item;
  p->next = *l;
  *l      = p;
}


template <class T>
ListNode<T> * predecessor_list(ListNode<T> * l, const T item){

  if((NULL == l) || (NULL == l->next)) {
    std::cerr << "ERROR: predecessor sought on null list.\n";
    return NULL;
  }

  if(item == (l->next)->item) return l;
  return predecessor_list(l->next, item);

}

template <class T>
void delete_list(ListNode<T> ** l, const T item){
  ListNode<T> * p;
  ListNode<T> * pred;
  ListNode<T> * search_list(), * predecessor_list();

  p = search_list(*l, item);
  if(NULL != p) {
    pred  = predecessor_list(*l, item);
    if(pred == NULL) *l = p->next;
    else  pred->next  = p->next;
    delete p;
  }
}

}
