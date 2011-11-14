/*
 * =====================================================================================
 *
 *       Filename:  pthread_scope.cpp
 *
 *    Description:  test on the pthread create scope
 *
 *        Version:  1.0
 *        Created:  11/09/2011 14:56:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <pthread.h>
#include <iostream>
#include <assert.h>
struct A {
  int t;
  int s;
};

static void * run(void * x) {
  A * a = (A*) x;
  for (int i = 0; i < 1000000; i++) {
    std::cout << a->t << " "  << a->s << std::endl;
  }
}

int main(){
  pthread_t p[100]; 
  for (int i = 0; i < 100; i++) {
    A temp;
    temp.t = i;
    temp.s = i*i;
    int r = pthread_create(&p[i], NULL, &run, (void *)&temp);
    assert(r==0);
  }
  for (int i = 0; i < 100; i++) {
    pthread_join(p[i], NULL);
  }
  return 0;
}

