// fstream::open
#include <fstream>
#include <iostream>
using namespace std;

int main () {

  fstream filestr;

  filestr.open ("1", fstream::in | fstream::out | fstream::app);
  if(filestr.good()) cout << "HHH\n" ; 
  
  // >> i/o operations here <<

  filestr.close();

  return 0;
}
