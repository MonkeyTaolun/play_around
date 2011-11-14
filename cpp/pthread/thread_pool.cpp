#include "thread_pool.hpp"
#include <stdio.h>

ThreadPool::ThreadPool(int number_workers)
  : worker_num_(number_workers),
    destroy_signal_(false)
{
  
  workers_ = new pthread_t[worker_num_];
  pthread_mutex_init(&queueLock_, NULL);
  pthread_cond_init(&cond_var_, NULL);
  for (size_t i = 0; i < worker_num_; ++i) {
    pthread_create(&workers_[i], NULL, &ThreadPool::thread_maker, (void *) this);
  } 
}

void ThreadPool::execution(){
  while(true) {
    Task task;
    pthread_mutex_lock(&queueLock_);
    if(taskQueue_.empty() && !destroy_signal_) {
      if(!destroy_signal_) printf("it is fucking false\n");
      printf("I am wairing\n");
      pthread_cond_wait(&cond_var_, &queueLock_);  
    }
    if(!taskQueue_.empty()) {
      task = taskQueue_.front();
      taskQueue_.pop();
    }
    else if (destroy_signal_){
      // already done
      pthread_mutex_unlock(&queueLock_);
      break;
    }
    pthread_mutex_unlock(&queueLock_);
    // work
    if(NULL != task.function) {
      (*task.function)(task.args);
    }
  }
  printf("out of bond\n");
}


void ThreadPool::addTask(Task task){
  if(!destroy_signal_) {
    printf("Added a task\n");
    pthread_mutex_lock(&queueLock_);
    taskQueue_.push(task);
    pthread_cond_signal(&cond_var_);
    pthread_mutex_unlock(&queueLock_);
  }
  return;
}

void * ThreadPool::thread_maker(void * pt) {
  ThreadPool * tp = (ThreadPool *) pt;
  tp->execution();
}

ThreadPool::~ThreadPool() {
  __sync_fetch_and_or(&destroy_signal_, true);


  pthread_cond_broadcast(&cond_var_);
  printf("this is deconstruction\n");
  for(size_t index = 0; index < worker_num_; ++index){
    pthread_join(workers_[index], NULL); 
  }
  printf("got here\n");
}

