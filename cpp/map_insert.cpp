/*
 * =====================================================================================
 *
 *       Filename:  map_insert.cpp
 *
 *    Description:  test on map insert function
 *
 *        Version:  1.0
 *        Created:  11/07/2011 19:34:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Taolun Chai, 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <map>

class A {
 public: 
  A(){
    aa = 0;
    std::cout << "constructing A with no element " << std::endl;
  }
  A(int a){
    aa = a;
    std::cout << "constructing A with " << a << std::endl;
  }
  A(const A &other) {
    this->aa = other.aa;
    std::cout << "constructing A with another A" << std::endl;
  }
  int aa;
};

int main(){
  std::pair <std::map<int, A>::iterator, bool> ret;
  std::map <int, A> map;
 // map[1] = A(2);

 // map[3] = A(3);
 // map[4] = A(4);
 // map[5] = A(5);
  A a = A(8);
  std::cout << std::endl;
  map[1] = a;
  std::cout << std::endl;
  A aa = map[8];
  std::cout << std::endl;
  ret = map.insert(std::pair<int, A>(20, A(20)));

  std::cout << std::endl;
  std::cout << map[20].aa << std::endl;
  return 0;
}
