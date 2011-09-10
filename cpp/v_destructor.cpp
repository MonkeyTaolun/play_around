#include <iostream>
using namespace std;

class Test{
public:
  virtual ~Test(){
    cout << "in destruct" << endl;
  }
};

int main(){
  Test T;
}
