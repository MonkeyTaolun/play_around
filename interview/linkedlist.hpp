/*
 * =====================================================================================
 *
 *       Filename:  linkedlist.hpp
 *
 *    Description:  header for linkedlist
 *
 *        Version:  1.0
 *        Created:  02/03/2012 12:31:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  MonkeyTaolun 
 *        Company:  
 *
 * =====================================================================================
 */
#include <string.h>
template <class T>
struct LinkedNode {
  T element;
  LinkedNode <class T> * next;
  LinkedNode();
  LinkedNode(const T);
};

template<class T> 
class LinkedList {
 public:
  void    put(const T );
  T *     get(const size_t );
  void    traverse()    const;
  bool    remove(const T);
  size_t  removeAll(const T);
  size_t  getLength()   const;
 private:
  T     * head;
  void    removeNext(T * const );
};


