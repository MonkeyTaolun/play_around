/*
 * =====================================================================================
 *
 *       Filename:  istreamtest.cpp
 *
 *    Description:  test for iostream
 *
 *        Version:  1.0
 *        Created:  11/06/2011 23:52:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <iostream>
#include <sstream>

int main(int argc, char * argv[]){
  // if(argc < 2) return -1;
  std::string str("12.231.23.123 123 123123123 1231231");
  std::istringstream ss(str);
  std::string ip;
  ss >> ip;
  int i;
  while(!ss.eof()) {
    ss >> i;
    std::cout << i << std::endl;
  }
  return 0;
}
