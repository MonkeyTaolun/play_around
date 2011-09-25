#include <iostream>
#include <list>

using namespace std;

int main(){

  list <int> l;
  for(int i = 0; i < 20; ++i){
    l.push_back(i);
    if(i % 5  ==  0) l.push_back(0);
  }
  

  list <int>::iterator it;
  
  for (it = l.begin(); it != l.end(); it++){
    cout << *it << " ";
  }
  cout << endl << endl;
  for (it = l.begin(); it != l.end();){
    if(*it == 0) it = l.erase(it);
    else it++;
  }
  for (it = l.begin(); it != l.end(); it++){
    cout << *it << " ";
  }
  cout << endl;
}
