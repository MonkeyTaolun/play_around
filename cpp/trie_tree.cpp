#include <iostream>
#include <string>
using namespace std;
struct TrieNode { 
  TrieNode* nextLevel[26];
  
  TrieNode(){
    for(int i = 0; i < 26; ++i) {
      nextLevel[i] = NULL;
    }
  }
  
  ~TrieNode() {
    for (int i = 0; i < 26; ++i) {
      if(NULL != nextLevel[i]) delete nextLevel[i];
    }
  }

};

class TrieTree {
private:
  TrieNode head;
public: 
  void insert(string s) {
    TrieNode *temp = &head;
    for (int i = 0; i < s.size(); ++i) { 
      int index = s[i] - 'a';
      if(temp->nextLevel[index] == NULL) {
        temp->nextLevel[index] = new TrieNode();
      }
      temp = temp->nextLevel[index];
    }
  }
  bool search(string s) {
    TrieNode *temp = &head;
    for (int i = 0; i < s.size(); ++i) {
      int index = s[i] - 'a';
      if(temp->nextLevel[index] == NULL) {
        return false;
      }
      temp = temp->nextLevel[index];
    }
    return true;
  }
};


int main(){
  TrieTree t;
  t.insert("abdddd");
  t.insert("adder");
  t.insert("dfadf");
  cout << t.search("abdddd") << endl;
  cout << t.search("dddd") << endl;
}
