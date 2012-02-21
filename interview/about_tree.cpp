// 
//  about_tree.cpp
//  interview stuff about tree
//  
//  Created by Taolun Chai on 2012-02-13.
//  Copyright 2012 MonkeyTaolun. All rights reserved.
// 


#include <iostream>
#include <queue>
struct TreeNode {
  // assume this is store the int
  int element;
  TreeNode * next;
  TreeNode * pre;
  TreeNode * left;
  TreeNode * right;
};


void link_same_level(TreeNode * const root){
  std::queue <TreeNode *> q1;
  q1.push(root);
  while(!q1.empty()) {
    std::queue <TreeNode *> q2;
    TreeNode * cur  = q1.front();
    TreeNode * pre  = NULL;
    q1.pop();
    cur->pre  = NULL;
    
    if(NULL !=  cur->left)  q2.push_back(cur->left);
    if(NULL !=  cur->right) q2.push_back(cur->right);
    
    while(!q1.empty()) {
      pre = cur;
      cur = q1.front();
      q1.pop();
      if(NULL !=  cur->left)  q2.push_back(cur->left);
      if(NULL !=  cur->right) q2.push_back(cur->right);
      cur->pre  = pre;
      pre->next = cur;
    }
    cur->next = NULL;
    q1  = q2;
  }
}