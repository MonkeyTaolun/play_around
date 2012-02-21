// 
//  about_set.cpp
//  interview warm up about set problem
//  
//  Created by Taolun Chai on 2012-02-13.
//  Copyright 2012 MonkeyTaolun. All rights reserved.
// 

#include <vector>

void _print_all_sub_set(const vector <int> & col, int i, vector <int> &output) {
  if (i >= col.size()) {
    print_vector(output);
  }
  else {
    output.push_back(col[i]);
    _print_all_sub_set(col, i+1, output);
    output.pop_back();
    _print_all_sub_set(col, i+1, output);
  }
}

void print_all_sub_set(const vector <int> & col) {
  vector<int> output;
  _print_all_sub_set(col, 0, output);
}

