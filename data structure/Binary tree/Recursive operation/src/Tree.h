#ifndef RECURSIVE_OPERATION_TREE_H
#define RECURSIVE_OPERATION_TREE_H
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void Make_Tree1(TreeNode* root);
void Make_Tree2(TreeNode* root);
void preorder_with_re(TreeNode* root);
void preorder_without_re(TreeNode* root);
void inorder_with_re(TreeNode* root);
void inorder_without_re(TreeNode* root);
void postorder_with_re(TreeNode* root);
void postorder_without_re(TreeNode* root);
void postorder_without_re2(TreeNode* root);
void level_order(TreeNode* root);
#endif //RECURSIVE_OPERATION_TREE_H
