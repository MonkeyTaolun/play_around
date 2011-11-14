#include <iostream>
#include <math.h>


int main(){
  int a[20];
  for (size_t i = 0; i < 20;i++){
    a[i] = i;
  }
  a[17] = 2;
  int temp = a[0];
  for(size_t i = 1; i < 20; ++i){
    temp ^= ~a[i];
    std::cout << temp << std::endl;
    // if(0 == temp) std::cout << i << std::endl;
  }
  return 0;
}
