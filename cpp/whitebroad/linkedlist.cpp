#include <iostream>
using namespace std;


template<class T>
struct  ListNode{
  T item;
  ListNode<T> * next;
  ListNode(T item): item(item), next(NULL) {}
};

template<class T>
class LinkedList{
private:
  ListNode <T>  * head;
public:
  LinkedList(): head(NULL) {}
  void insert(const T item){
    ListNode<T> *  temp  = new ListNode<T>(item);
    temp->next  = head;
    head  = temp;
  }

  void print(){
    ListNode<T> * temp  = this->head;
    while(temp){
      cout  <<  temp->item  << " ";
      temp  = temp->next;
    }

    cout << endl;
  }

  void earseNodes(const T item){
    ListNode<T> * temp  = this->head;
    while(temp  && item == temp->item){
      this->head  = temp->next;
      delete temp;
      temp  = this->head;
    }
    if(!temp) return;
    ListNode<T> * tempNext  = temp->next;
    while(tempNext){
      if(item ==  tempNext->item){
        temp->next  = tempNext->next;
        delete tempNext;
        tempNext  = temp->next;
      }

      temp  = tempNext;
      if(!temp) break;
      tempNext  = temp->next;
    }
  }
};


int main(){
  LinkedList <int>  list;
  for(int i = 0;  i < 10; ++i){
    list.insert(i);
  }
  list.print();
  for(int i = 0;  i < 4; ++i){
    list.insert(i);
  }
  list.print();

  list.earseNodes(0);
  list.print();

  list.earseNodes(3);
  list.print();

}
