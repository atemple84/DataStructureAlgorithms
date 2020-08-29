#include "BinarySortTree.h"

#include <iostream>
#include <queue>

void printBinaryTree(TreeNode* root)
{
    if (!root)
        return;

    cout << root->val << ": ";
    if (root->left)
        cout << "L" << root->left->val;

    if (root->right)
        cout << "R" << root->right->val;
    cout << endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

TreeNode* takeInputBinaryTree()
{
    cout << "Enter data:" << endl;
    int data;
    cin >> data;
    if (data == -1)
        return NULL;

    TreeNode* root = new TreeNode(data);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        auto top = q.front();
        q.pop();

        cout << "Enter left:" << endl;
        cin >> data;
        if (data != -1)
        {
            TreeNode* left = new TreeNode(data);
            top->left = left;
            q.push(left);
        }

        cout << "Enter right:" << endl;
        cin >> data;
        if (data != -1)
        {
            TreeNode* right = new TreeNode(data);
            top->right = right;
            q.push(right);
        }
    }

    return root;
}

TreeNode* searchBST(TreeNode* root, int val)
{
    if (!root)
        return nullptr;

    while (root)
    {
        if (root->val == val)
            return root;
        if (root->val > val)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;

    /*
    if (root->val == val)
        return root;

    return root->val > val ? searchBST(root->left, val) : searchBST(root->right, val);
    */
}

int rangeSumBST(TreeNode* root, int L, int R)
{
    if (!root)
        return 0;

    int sum = 0;
    if (root->val <= R && root->val >= L)
        sum += root->val;

    if (root->val > R)
        sum += rangeSumBST(root->left, L, R);
    else if (root->val < L)
        sum += rangeSumBST(root->right, L, R);
    else
        sum += rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);

    return sum;
}

bool isValidBST(TreeNode* root, vector<int>& nodes)
{
    if (!root)
        return true;

    bool leftValid = isValidBST(root->left, nodes);
    if (!leftValid)
        return false;
    if (!nodes.empty() && *(nodes.end() - 1) >= root->val)
        return false;
    nodes.push_back(root->val);
    return isValidBST(root->right, nodes);
}

bool isValidBST(TreeNode* root, long min, long max)
{
    if (!root)
        return true;

    if (root->val <= min || root->val >= max)
        return false;

    return isValidBST(root->right, root->val, max) && isValidBST(root->left, min, root->val);
}

bool isValidBST(TreeNode* root)
{
    if (!root)
        return true;

    return isValidBST(root, LONG_MIN, LONG_MAX);
}

TreeNode* sortedArrayToBST(vector<int>& nums, int s, int n)
{
    if (s > n)
        return nullptr;

    int mid = s + (n - s) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(nums, s, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, n);

    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
    if (nums.empty())
        return nullptr;
    return sortedArrayToBST(nums, 0, nums.size() - 1);
}

bool BST::hasData(TreeNode* node, int data)
{
    if (!node)
        return false;
    if (node->val == data)
        return true;
    if (root->val > data)
        return hasData(node->left, data);
    else
        return hasData(node->right, data);
}

TreeNode* BST::insert(TreeNode* node, int data)
{
    if (!node)
        return new TreeNode(data);

    if (node->val > data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);

    return node;
}

TreeNode* BST::deleteData(TreeNode* node, int data)
{
    if (!node)
        return nullptr;

    if (node->val > data)
        node->left = deleteData(node->left, data);
    else if (node->val < data)
        node->right = deleteData(node->right, data);
    else
    {
        if (!node->left && !node->right)
        {
            delete node;
            return nullptr;
        }
        else if (!node->left)
        {
            TreeNode* tmp = node->right;
            node->right = nullptr;
            delete node;
            return tmp;
        }
        else if (!node->right)
        {
            TreeNode* tmp = node->left;
            node->left = nullptr;
            delete node;
            return tmp;
        }
        else
        {
            TreeNode* minNode = node->right;
            while (minNode->left)
            {
                minNode = minNode->left;
            }
            int rightMin = minNode->val;
            node->val = rightMin;
            node->right = deleteData(node->right, rightMin);
        }
    }

    return node;
}

void BST::deleteData(int data)
{
    root = deleteData(root, data);
}

void BST::insert(int data)
{
    root = insert(root, data);
}

void BST::print()
{
    printBinaryTree(root);
}

pair<TreeNode*, TreeNode*> BST::convertToLL(TreeNode* root)
{
    if (!root)
        return pair<TreeNode*, TreeNode*>();
    else if (!root->left && !root->right)
    {
        pair<TreeNode*, TreeNode*> p = make_pair(root, root);
        return p;
    }
    else if (!root->right)
    {
        pair<TreeNode*, TreeNode*> leftLL = convertToLL(root->left);
        leftLL.second->right = root;
        root->left = nullptr;
        return make_pair(leftLL.first, root);
    }
    else if (!root->left)
    {
        pair<TreeNode*, TreeNode*> rightLL = convertToLL(root->right);
        root->right = rightLL.first;
        return make_pair(root, rightLL.second);
    }
    else
    {
        pair<TreeNode*, TreeNode*> leftLL = convertToLL(root->left);
        pair<TreeNode*, TreeNode*> rightLL = convertToLL(root->right);
        leftLL.second->right = root;
        root->left = nullptr;
        root->right = rightLL.first;
        return make_pair(leftLL.first, rightLL.second);
    }
}
