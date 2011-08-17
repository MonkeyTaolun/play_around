#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
template <class insert_iterator>
void test(insert_iterator result){
  for(int i = 0; i < 100; i++){
    *result = i;
    cout << *result << endl;
    result++;
  }
}


int main(){
  vector   <int> test_vec(100);
  
  vector <int>::iterator it;
  test(test_vec.begin()); 
  for(it = test_vec.begin(); it != test_vec.end(); ++it){
    cout << *it << " ";
  }
  cout << endl;
  return 0;
  
}
