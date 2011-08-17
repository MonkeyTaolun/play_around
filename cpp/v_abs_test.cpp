#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
template <class OutputIterator>
void test(OutputIterator result){
  for(int i = 0; i < 100; i++){
    *(result++) = i;
    //cout << *result << endl;
    //result++;
  }
}


int main(){
  vector   <int> test_vec;
  
  vector <int>::iterator it;
  test(back_inserter(test_vec)); 
  for(it = test_vec.begin(); it != test_vec.end(); ++it){
    cout << *it << " ";
  }
  cout << endl;
  return 0;
  
}
