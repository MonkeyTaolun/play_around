// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to start entering input data.
#include <iostream>
#include <algorithm>
using namespace std;

int lengthOfLongestSubString(string s){
  int n = s.length();
  int i = 0, j = 0;
  int exits[256];
  int maxLen = 0;
  for(int k = 0; k < 256; ++k) {
    exits[k] = -1;
  }
  while(j < n) {
    if(exits[s[j]] > 0) {
      maxLen = max(maxLen, j - exits[s[j]]);
    }
    exits[s[j]] = j;
    j++;
  }
  maxLen = max(maxLen ,n - exits[s[n-1]]);
  return maxLen;
}

int main() {
  // Start typing your code here...

  cout << lengthOfLongestSubString("hahahah") << endl;
  cout << lengthOfLongestSubString("abcabc") << endl;
  cout << lengthOfLongestSubString("aaaaaaaaa") << endl;
  return 0;
}
