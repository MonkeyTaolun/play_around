// 
//  partition.cpp
//  Interview stuff about partition problems
//  
//  Created by Taolun Chai on 2012-02-13.
//  Copyright 2012 MonkeyTaolun. All rights reserved.
// 


void partition(int v[], int n; int key) {
  int i = 0;
  int j = n - 1;
  while(i < j) {
    if (v[i] >= key) {
      std::swap(v[i], v[j]);
      --j;
    }
    else i++;
    
    if (v[j] < key) {
      std::swap(v[i], v[j]);
      ++i;
    }
    else --j;
  }
}