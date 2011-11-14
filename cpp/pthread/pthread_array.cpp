#include <pthread.h>

#include <stdio.h>

void * work(void * a) {
  int * num = (int *) a;
  for(size_t index = 0; index < 100; ++index) {
    printf("Haha, I am thread number : %d\n", *num); 
  }
}

int main(){
  pthread_t * th;
  th = new pthread_t[10];
  int *times = new int [10];
  for(int i = 0; i < 10; ++i) {
    times[i] = i;
    pthread_create(&th[i], NULL, &work, (void *) &times[i]);
  }


  for (int i = 0; i < 10; ++i){
    pthread_join(th[i], NULL);
  }
  

  printf("HAHA the main thread is done\n");

  return 0;
}
