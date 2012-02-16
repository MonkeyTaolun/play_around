#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector <int> find_intersect(const vector <int> & v1, const vector <int> & v2) {
  int index1  = 0;
  int index2  = 0;
  vector <int> ret;
  while(index1 < v1.size() && index2 < v2.size()) {
    if(v1[index1] == v2[index2]) {
      ret.push_back(v1[index1]);
      index1++;
      index2++;
    }else {
      if(v1[index1] > v2[index2]) index2++;
      else index1++;
    }
  }
  return ret;
}

// need to verify
int partition(int v[], int l, int r) {
  int key = v[l];
  int p = l+1;
  while(p <= r) {
    if(v[p] >= key) {
      std::swap(v[p], v[r]);
      r--;
    }
    else p++;
  }  
  std::swap(v[l], v[p-1]);
  return p-1;
}

void qsort(int v[], int l, int r) {
  if(l >= r) return;
  int p = partition(v, l, r);
  qsort(v, l, p-1);
  qsort(v, p+1, r);
}

void sort_stack(stack<int> &s) {
  stack<int> desk;
  while(!s.empty()) {
    if(desk.empty() || s.top() >= desk.top()) {
      desk.push(s.top());
      s.pop();
    }
    else {
      stack<int> tmp;
      while(!desk.empty() && desk.top() > s.top()) {
        tmp.push(desk.top());
        desk.pop();
      }
      desk.push(s.top());
      s.pop();
      while(!tmp.empty()) {
        desk.push(tmp.top());
        tmp.pop();
      }
    }
  }
  s = desk;
}



int main(int argc, char * argv[]) {
  vector<int> v1;
  vector<int> v2;
  for(int i = 0; i < 100; ++i) {
    v1.push_back(i);
    v2.push_back(-50 + 2 * i);
  } 
  /*
  for(int i = 0; i < 100; ++i) {
    cout << v1[i] << " " ;
    cout << v2[i];
    cout << endl;
  }
  */
  vector <int> ret  = find_intersect(v1, v2);
  for (int  i = 0;  i< ret.size(); ++i) {
    cout << ret[i] << " ";
    if(0  ==  (i+1) % 8) cout << endl;
  }
  return 0;
}