#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};
  
// A class for BST
class BST 
{ 

public: 
    BST(){root_ = NULL;};
    BST(vector<int> init_v);
    ~BST(){};

    void push(int key);
    bool find(int key);
    bool erase(int key);
    vector<int> print();

    vector<int> NonRecursiveInorderTraveral();
    vector<int> RecursiveInorderTraveral();

    int MaxDep();
    int kthSmallest(int k);

    
private:
    TreeNode * root_;
}; 

#endif