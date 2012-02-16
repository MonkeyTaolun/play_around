#include <iostream>
using namespace std;
struct TT {
  int value;
};
void ttt(TT * const a) {
  a->value = 7;
}
int main(){
  char * a = new char [20];
  for(int i = 0; i < 10; i++){
    a[i] = 'a' + i;
  }
  a[10] = '\0';
  TT b;
  // ttt(a);
}
