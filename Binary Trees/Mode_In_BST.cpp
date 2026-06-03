#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};


vector<int> findMode(TreeNode* root) 
{
    vector<int> modes;
    int currentCount = 0;
    int maxCount = 0;
    TreeNode* prev = nullptr;
    
    findModeHelper(root, prev, currentCount, maxCount, modes);
    
    return modes;
}

void findModeHelper(TreeNode* node, TreeNode*& prev, int& currentCount, int& maxCount, vector<int>& modes) 
{
    if (node == nullptr) 
    {
        return;
    }
    
    findModeHelper(node->left, prev, currentCount, maxCount, modes);
    
    if (prev != nullptr && node->val == prev->val) 
    {
        currentCount++;
    } 
    else 
    {
        currentCount = 1;
    }
    
    if (currentCount > maxCount) 
    {
        maxCount = currentCount;
        modes.clear();
        modes.push_back(node->val);
    } 
    else if (currentCount == maxCount) 
    {
        modes.push_back(node->val);
    }
    
    prev = node;
    
    findModeHelper(node->right, prev, currentCount, maxCount, modes);
}

