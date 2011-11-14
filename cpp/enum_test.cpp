#include <iostream>
#include <map>

struct LockStatus {
  enum xxstatus {NONE, FREE, LOCKED};
  typedef int status;
};

struct LockInfo {
  LockStatus::status status;
  int sequenceID;
  LockInfo() : status(LockStatus::NONE), sequenceID(0) {}
};
typedef std::map <int, LockInfo> myMap;
int main(){
  myMap map;

  std::cout << map[1].sequenceID++ << std::endl;
  std::cout << map[1].sequenceID++ << std::endl;
  std::cout << map[1].sequenceID++ << std::endl;
  std::cout << map[1].status       << std::endl;
  return 0;
}
