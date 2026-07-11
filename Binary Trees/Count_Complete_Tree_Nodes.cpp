#include<iostream>


using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int countNodes(TreeNode* root) {
    if (!root) return 0;

    int leftDepth = 0, rightDepth = 0;
    TreeNode* leftNode = root;
    TreeNode* rightNode = root;

    while (leftNode) {
        leftDepth++;
        leftNode = leftNode->left;
    }

    while (rightNode) {
        rightDepth++;
        rightNode = rightNode->right;
    }

    if (leftDepth == rightDepth) {
        return (1 << leftDepth) - 1; 
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}
