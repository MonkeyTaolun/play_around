#include <iostream>
#include <vector>

#include <stdlib.h>
#include <time.h>


using namespace std;

inline void swap(int &a, int &b){
  a ^=  b;
  b =   b^a;
  a =   a^b;
}

//void dutchnationflag(vector <int> & vec){
//  int p = -1, q = vec.size();
//  for(int i = 0; i < q; ){
//    switch(vec[i]) {
//      case 0:
//        swap(vec[i], vec[++p]);
//        i++;
//        break;
//      case 1:
//        //swap(vec[i], vec[1 + r + w++]);
//        i++;
//        break;
//      case 2:
//        swap(vec[i], vec[--q]);
//        break;
//      default:
//        cerr << "Error\n";
//        exit(-1);
//    }
//  }
//  // swap(vec[q], vec[p]);
//}
//


void threePart(int * data, int num){
  int p = -1, q = num;
  for(int i = 0; i < q;){
    if(data[i] == 0){
      swap(data[i], data[++p]);
      i++;
    }
    else if(data[i] == 2) swap(data[i], data[--q]);
    else i++;
  }
  // cout << "STOP at q is " << q << " " <<  data[q] << " p is " <<p << " "<< data[p]<< endl;
  if(data[q] == 0) swap(data[q], data[p + 1]);
}

int main(int argc, char * argv[]){

  int total = argc > 1 ? atoi(argv[1]) : 100;

  srand(time(NULL));
  int * data  = new int [total];
  // vector <int> vec;
  for(int i = 0; i < total; i++){
    //vec.push_back(rand()%3);
    data[i] = rand() % 3;
  }
  
  for(int i = 0; i < total; i++){
    cout << data[i] << " ";
    if((i+1)%10 == 0) cout << endl;
  }
  
  threePart(data, total);
  //dutchnationflag(vec);
  cout << "After \n\n";
  for(int i = 0; i < total; i++){
    cout << data[i] << " ";
    if((i+1)%10 == 0) cout << endl;
  }

  delete [] data;
  return 0;
}
