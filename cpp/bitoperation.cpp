#include <iostream>
using namespace std;

bool bitGet(int a, int index) {
  int mask = (1 << index);
  return a & mask != 0;
}

int bitSet(int a, int index) {
  return a | (1 << index);
}

int bitClear(int a, int index) {
  return a & (~(1 << index)) ;
}

// clear from 0 to index
int bitclearbegin(int a, int index) {
  int mask = (1 << (index + 1)) - 1;
  return a & mask;
}

// clear from index to the end;
int bitclearend(int a, int index) {
  int mask = ~((1 << (index + 1) ) - 1);
  return a & mask;
}

int bitUpdate(int a, int index, int val) {

  int mask = ~(1 << index);
  return a & mask | (val << index);
}

int main(){
  int a = 1023;
  int b = 0;
  int c = 1024;
  cout << bitGet(a, 5) << endl;
  cout << bitSet(b,6) << endl;
  cout << bitClear(a, 5) << endl;
  cout << bitclearbegin(a, 5) << endl;
  cout << bitclearend(a, 7) << endl;
  cout << bitUpdate(c, 10, 0) << endl;
  cout << (1 << 31) << endl;
}
