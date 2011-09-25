#include <vector>
#include <iostream>

using namespace std;

int main(){
  vector <int> a;
  vector <int> b;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  for(int i = 0; i < 10000;  ++i) a.push_back(i);
  b.push_back(1);
  vector <int> c = a;
  cout << c.size() << endl;
  cout << sizeof(a) << endl;
  cout << sizeof(b) << endl;

}
