#include <iostream>
#include <string>
using namespace std;

void replace(char * const args, int length) {

  int length_new = length;
  int space_count = 0;
  for(int i = 0; i < length; ++i){
    if(args[i] == ' ') {
      space_count++;
      length_new += 2;
    }
  }
  for(int i = length - 1; i>=0; --i){
    if(args[i] == ' '){
      args[length_new - 1] = '0';
      args[length_new - 2] = '2';
      args[length_new - 3] = '%';
      length_new -= 3;
    }
    else {
      args[length_new - 1] = args[i];
      --length_new;
    }
  }
}

int main() {
  char text[200] = "sdhahd adfhad fadf adhfad fasdfas dad fadsf ad";
  cout << text << endl;
  replace(text, 47);
  cout << text << endl;
}

