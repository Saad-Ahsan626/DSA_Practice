#include<iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumOfLeftLeaves(TreeNode* root) 
{
    if (root == NULL) 
    {
        return 0;
    }
    
    int sum = 0;
    
    if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) 
    {
        sum += root->left->val;
    }
    
    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);
    
    return sum;
}
