#include "thread_pool.hpp"
#include <stdio.h>
void * work(void * a) {
  int * num = (int *) a;
  for(size_t index = 0; index < 100; ++index) {
    printf("Haha, I am thread number : %d\n", *num); 
  }
}

int main(){
  ThreadPool * tp = new ThreadPool(10);
  int *times = new int [10000];
  for(int i = 0; i < 100; ++i){
    times[i] = i;

    Task temp;
    temp.function  = work;
    temp.args      = (void *)&times[i];
    tp->addTask(temp);
  }
  delete tp; 
  return 0;
}
