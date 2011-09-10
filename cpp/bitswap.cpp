#include <iostream>
using namespace std;
void bitSwap(int &a, int &b){
  a ^= b;
  b = a ^ b;
  a = b ^ a;
}
int main(){
  int a = 5;
  int b = 29999;
  cout << a << " " << b << endl;
  bitSwap(a, b);
  cout << a << " " << b << endl;
}
