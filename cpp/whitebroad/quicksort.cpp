#include <iostream>
#include <algorithm>

#include <stdlib.h>
#include <time.h>

template <class T>
int partition(T * array,  int from, int to){
  int p, q  = to + 1;
  for(p = from+1; p < q;){
    if(array[p] > array[from]) std::swap(array[p], array[--q]);
    else p++;
  }
  std::swap(array[q-1], array[from]);
  return q-1;
}

template <class T>
void  quicksort(T  * array, int from, int to){
  if(from >= to ) return;
  int part = partition(array, from, to);
  quicksort(array, from, part - 1);
  quicksort(array, part + 1, to);
}

int main(int argc, char * argv[]){
  int total = argc > 1 ? atoi(argv[1]) : 20;
  srand(time(NULL));

  int * data  = new int [total];

  for(int i = 0;  i < total;  ++i)  data[i] = rand() % 100;
  
  for(int i = 0;  i < total;  ++i)  {
    std::cout << data[i] << " ";
    if((i+1) % 10 ==  0) std::cout << std::endl;
  }
  quicksort(data, 0, total - 1);
  std::cout << std::endl << "after\n";
  for(int i = 0;  i < total;  ++i)  {
    std::cout << data[i] << " ";
    if((i+1) % 10 ==  0) std::cout << std::endl;
  }
 
}
