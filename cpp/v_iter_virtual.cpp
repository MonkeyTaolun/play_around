#include <iterator>
#include <vector>
#include <iostream>


class Test {
public:
  virtual void test(std::back_inserter <int> result) const   = 0;
};


class Tester : public Test {
public:
  void test(std::back_inserter <int> result) const{
    for(int i = 0; i < 100; i++){
      *result++ = i;
    }
  }
};


int main(){
  
  std::vector   <int> test_vec;
  Tester tt;
  tt.test(back_inserter(test_vec));
  std::vector <int>::iterator it;
 
  for(it = test_vec.begin(); it != test_vec.end(); ++it){
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  return 0;
  

}
