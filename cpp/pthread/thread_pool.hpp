#ifndef __DS_THREAD_POOL_HPP__
#define __DS_THREAD_POOL_HPP__
#include <pthread.h>
#include <queue>

typedef void* (* p_function) (void *); 

struct Task {
  p_function function;
  void * args;
  Task() : function(NULL), args(NULL) {}
};

class ThreadPool {
 public:
  explicit ThreadPool(int number_workers);
  ~ThreadPool();
  void addTask(Task task);
 private:
  int                                       worker_num_;
  bool                                      destroy_signal_;
  pthread_t                               * workers_;
  std::queue <Task>                         taskQueue_;
  pthread_mutex_t                           queueLock_;   
  pthread_cond_t                            cond_var_;

  void execution();
  static void * thread_maker(void *);
};

#endif
