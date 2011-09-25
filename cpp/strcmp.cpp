#include <iostream>
#include <string>
using namespace std;
int mystrcmp(const char *s1, const char *s2) {
  // return 1 if s1 is greater, -1 if s2 is greater, 0 if equal
  if(s1==NULL && s2==NULL) return 0;
  cout <<"WTF"<<endl;
  if(s1==NULL) return -1;
  if(s2==NULL) return 1;
  int index1 = 0;
  int index2 = 0;
  while(s1[index1]!='\0'||s2[index2]!='\0'){
   cout << s1[index1] << " " << s2[index2] << "\n"; 
   if(s1[index1]==s2[index2]){
      index1++;
      index2++;
    }
    else return (s1[index1] > s2[index2] ? 1 : -1);
  }
  return 0;
}

int main(int argc, char * argv[]){
  string s1, s2;
  if(argc < 3) {
    cin >> s1 >> s2;
  }else{
    s1=argv[1];
    s2=argv[2];
  }
  cout << mystrcmp(s1.c_str(), s2.c_str()) << endl;
  cout << mystrcmp("",s1.c_str()) << endl;
}
