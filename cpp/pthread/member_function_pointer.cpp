#include <iostream>
#include <string>
#include <pthread.h>
using namespace std;

class example
{
  public:
    string s;
    void say_hi()
    {
      cout<<"hello "<<s<<endl;
    }

    void (example::*func())()
    {
      return &example::say_hi;
    }

    void get_hi()
    {
      void ((example::*foo)()) =  func();
      (this->*foo)();
    }

    static void* thread_maker(void* dat_s);
};

struct val_st
{
  example* e;
  void (example::*func)();
};

//moved this out of the class definition since we need to reference val_st structure
void* example::thread_maker(void* dat_s)
{
  struct val_st* v = static_cast<val_st*>(dat_s);
  example* e = v->e;
  void ((example::*f)()) = v->func;
  (e->*f)();
  return NULL;
}

int main()
{
  pthread_t launch_thread;
  example foo;
  example bar;
  val_st v;
  foo.s = "world";
  bar.s = "there";
  foo.get_hi();
  bar.get_hi();
  void ((example::*f)()) =  bar.func();
  (foo.*f)();
  v.e = &foo;
  v.func = foo.func();
  pthread_create(&launch_thread, NULL, &example::thread_maker, static_cast<void*>(&v));
  pthread_join(launch_thread,NULL);
  return 0;
}
