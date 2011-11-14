#include <iostream>
#include <limits.h>
using namespace std;

int main(){

  size_t result = 0;
  for(size_t i = 0; i <= USHRT_MAX; i++) {
    if(i != 15) result ^= i;
  }
  std::cout << result << endl;
}
