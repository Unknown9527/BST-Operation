#include "solution.h"
#include <iostream>
#include <queue>

using namespace std;

BST::BST(vector<int> init_v)
{
    for(int i: init_v){
        push(i);
    }
}

TreeNode * recursive_find(TreeNode* node, int key)
{
    if(node == NULL){
        return NULL;
    }
    else if (key < node->val){
        return recursive_find(node->left, key);
    }
    else if (key > node->val){
        return recursive_find(node->right, key);
    }
    else{
        return node;
    }
}

TreeNode * FindMin(TreeNode* node)
{
    if (node == NULL)
    {
        return NULL;
    }
    else if (node->left == NULL)
    {
        return node;
    }else
    {
        return FindMin(node->left);
    }
}

TreeNode * recursive_remove(int key, TreeNode * node)
{
    TreeNode * n;
    if(node == NULL){
        return NULL;
    }
    else if (key < node->val){
        node->left = recursive_remove(key, node->left);
    }
    else if (key > node->val){
        node->right = recursive_remove(key, node->right);
    }
    else if (node->left && node->right)
    {
        n = FindMin(node->right);
        node->val = n->val;
        node->right = recursive_remove(node->val, node->right);
    }
    else
    {
        n = node;
        if (node->left == NULL)
        {
            node = node->right;
        }
        else if (node->right == NULL)
        {
            node = node->left;
        }

    }
    return node;

}

bool BST::erase(int key)
{
    TreeNode * node = recursive_find(root_,key);
    if (node != NULL)
    {
        TreeNode * node = recursive_remove(key, root_);
        return true;
    }
    else{return false;}
}


bool BST::find(int key)
{
    TreeNode * node = recursive_find(root_,key);
    if(node != NULL){return true;}
    else{return false;}
}

TreeNode * compare_insert(TreeNode * n, int key)
{
    if( n == NULL){
        n = new TreeNode(key);

    }
    else if(key < n->val){
        n->left = compare_insert(n->left, key);
    }
    else if(key > n->val){
        n->right = compare_insert(n->right, key);
    }
    return n;

}

void BST::push(int key)
{
    root_ = compare_insert(root_, key);
}

vector<int> BST::print()
{
    vector<int> output;
    if(root_ == NULL){
        return output;
    }

    queue<TreeNode *> q;

    q.push(root_);

    while(!q.empty()){
        TreeNode * node = q.front();
        output.push_back(node->val);
        cout << node->val << " ";
        q.pop();

        if(node->left!=NULL){
            q.push(node->left);
        }

        if(node->right!=NULL){
            q.push(node->right);
        }
    }
    cout << endl;
    return output;

}

// HW5 Q1

// find BST Deepth
int BST::MaxDep()
{
    TreeNode * node;
    if (node == NULL)
    {
        return 0;
    }

    queue<TreeNode *> que;
    que.push(root_);

    int height = 0;

    while (1)
    {
        int nodeCount = que.size();
        if (nodeCount == 0)
        {
            return height;
        }
        height++;
        
        while (nodeCount > 0)
        {
            TreeNode *node = que.front();
            que.pop();
            if (node->left != NULL)
            {
                que.push(node->left);
            }
            if (node->right != NULL)
            {
                que.push(node->right);
            }
            nodeCount--;
              
        }
        
    }
    
}

// HW5 Q2
void inorder(TreeNode * node, vector<int> &output)
{
    if (node)
    {
        // cout << node->val << " ";
        inorder(node->left, output);
        output.push_back(node->val);
        inorder(node->right, output);
        // cout << node->val << " ";
    }
    
}

// Recursive Inorder
vector<int> BST::RecursiveInorderTraveral()
{
    // TreeNode * node;
    // vector<int> output;
    vector<int> output;
    inorder(root_, output);
    for(auto x : output){
        cout << x << " ";
    }
    cout << endl;
    return output; 

}


// Non Recursive Inorder
vector<int> BST::NonRecursiveInorderTraveral()
{
    vector<int> output;
    if (!root_) 
    {
        return output;
    }
    TreeNode *cur, *pre;
    cur = root_;
    while (cur) 
    {
        if (!cur->left) 
        {
            cout << cur->val << " ";
            output.push_back(cur->val);
            cur = cur->right;
        } else 
        {
            pre = cur->left;
            while (pre->right && pre->right != cur) 
            {
                pre = pre->right;
            }
            if (!pre->right) 
            {
                pre->right = cur;
                cur = cur->left;
            } else 
            {
                pre->right = NULL;
                cout << cur->val << " ";
                output.push_back(cur->val);
                cur = cur->right;
                
            }
        }
    
    }
    cout << endl;
    return output;
    
}

// return the kth smallest element in BST
int BST::kthSmallest(int k)
{
    // print BST
    vector<int> output;
    if(root_ == NULL){
        return 0;
    }

    queue<TreeNode *> q;

    q.push(root_);

    while(!q.empty()){
        TreeNode * node = q.front();
        output.push_back(node->val);
        node->val;
        q.pop();

        if(node->left!=NULL){
            q.push(node->left);
        }

        if(node->right!=NULL){
            q.push(node->right);
        }
    }
    // sort the BST vector from small to large
    sort(output.begin(), output.end());
    // since the index begin at 0
    int res = output[k - 1];
    return res;
    
}
