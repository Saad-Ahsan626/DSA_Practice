#include<iostream>
#include<algorithm>


using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int depth(TreeNode* root, int& diameter) 
{
    if (!root) return 0;
    
    int leftDepth = depth(root->left, diameter);
    int rightDepth = depth(root->right, diameter);
    
    diameter = max(diameter, leftDepth + rightDepth);
    
    return max(leftDepth, rightDepth) + 1;
}

int diameterOfBinaryTree(TreeNode* root) 
{
    int diameter = 0;
    depth(root, diameter);
    return diameter;
}

