#include <iterator>
#include <vector>
#include <iostream>

using namespace std;

class Test {
public:
  template<class insert_iterator>
  void test(insert_iterator result) {
    _do_detect();
  }
protected:
  void _do_detect() const {
    throw "test NO be implement!";
  }
};


class Tester : public Test {
public:
  template <class insert_iterator>
  void test(insert_iterator result){
    for(int i = 0; i < 100; i++){
      cout << i << endl;
      *result++ = i;
     // result++;
    }
  }
};


class Tester2 : public Test{ 
};


int main(){
  
  vector   <int> test_vec;
  Tester t;
  Tester2 tt;
  insert_iterator <vector <int> > ll (test_vec,test_vec.begin());
  t.test(ll);
  vector <int>::iterator it;
  
  for(it = test_vec.begin(); it != test_vec.end(); ++it){
    cout << *it << " ";
  }
  cout << endl;
  return 0;
  

}
