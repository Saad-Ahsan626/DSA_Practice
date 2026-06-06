#include<iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

int height(TreeNode* node) 
{
    if (node == nullptr) {
        return 0; 
    }
    
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    
    return max(leftHeight, rightHeight) + 1; 
}

bool isBalanced(TreeNode* root) 
{
    if (root == nullptr) {
        return true; 
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) > 1) {
        return false; 
    }

    return isBalanced(root->left) && isBalanced(root->right);
}
