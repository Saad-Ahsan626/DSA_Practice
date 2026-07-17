#include<iostream>
#include<vector>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void dfs(TreeNode* node, string current_path, vector<string>& paths) 
{
    current_path += to_string(node->val);
        
    if (!node->left && !node->right) 
    {
        paths.push_back(current_path);
        return;
    }
        
    if (node->left) 
    {
        dfs(node->left, current_path + "->", paths);
    }
    if (node->right) 
    {
        dfs(node->right, current_path + "->", paths);
    }
    }

vector<string> binaryTreePaths(TreeNode* root) 
{
    vector<string> paths;
    if (root) 
    {
        dfs(root, "", paths);
    }
    return paths;
}


