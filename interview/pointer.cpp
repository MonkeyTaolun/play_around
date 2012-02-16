#include <iostream>

int main(){
  int * p = new int [10];
  int pp  = 7;
  std::cout <<  sizeof(p)     << std::endl;
  std::cout <<  sizeof(*p)    << std::endl;
  std::cout <<  sizeof(pp)    << std::endl;
  return 0;  
}