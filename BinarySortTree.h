#pragma once

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    ~TreeNode() { delete left; delete right; }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void printBinaryTree(TreeNode* root);
TreeNode* takeInputBinaryTree();
TreeNode* searchBST(TreeNode* root, int val);
int rangeSumBST(TreeNode* root, int L, int R);
bool isValidBST(TreeNode* root);
TreeNode* sortedArrayToBST(vector<int>& nums);

class BST
{
    TreeNode* root;

public:
    BST() : root(nullptr) {}
    virtual ~BST() { delete root; }

    void deleteData(int data);
    void insert(int data);
    bool hasData(int data) { return hasData(root, data); }
    void print();
    TreeNode* convertToLL() { return convertToLL(root).first; }

private:
    bool hasData(TreeNode* node, int data);
    TreeNode* insert(TreeNode* node, int data);
    TreeNode* deleteData(TreeNode* node, int data);
    pair<TreeNode*, TreeNode*> convertToLL(TreeNode* node);
};
