#include <iostream>


class Base  {
 public:
  virtual ~Base() {
    std::cout << "I am base" << std::endl;
  }
};

class Devited : public Base {
 public:
  virtual ~Devited () {
    std::cout << "I am devited " << std::endl;
  }
};

int main(){
  Base * p = new Devited();
  delete p;

  Devited d;
  return 0;
}
