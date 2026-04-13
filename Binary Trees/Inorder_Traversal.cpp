#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
    TreeNode(int value, TreeNode* leftChild, TreeNode* rightChild) : val(value), left(leftChild), right(rightChild) {}
};

vector<int> inorderTraversal(TreeNode* root) {

    vector<int> result;
    if(root == nullptr)
        return result;
    
    vector<int> left = inorderTraversal(root->left);
    result.insert(result.end(), left.begin(), left.end());

    result.push_back(root->val);

    vector<int> right = inorderTraversal(root->right);
    result.insert(result.end(), right.begin(), right.end());
    
    return result;
}
