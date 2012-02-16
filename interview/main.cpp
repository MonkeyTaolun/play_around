#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>

class A {
public:
  A() {std::cout << "A" << std::endl;}
};

class Su1 : public virtual A {};

class Su2 : public A {};
class Su4 : public A {};

class Su5 : public Su4, public Su2 
{};

class Su3 : public Su1, public Su2 
{};


int main() {
  Su3 a;

  Su2 b;
  Su1 c;
  Su5 d;
  return 0;
}
