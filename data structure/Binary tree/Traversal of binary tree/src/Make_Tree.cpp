#include "Tree.h"

void Make_Tree1(TreeNode* root){
    // 构建一棵普通的二叉树
    // 第1层
    root->val = 1;
    // 第2层
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    // 第3层
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    // 第4层
    root->left->right->right = new TreeNode(6);
}

void Make_Tree2(TreeNode* root){
    // 构建一棵二叉搜索树
    // 第1层
    root->val = 8;
    // 第2层
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    // 第3层
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    // 第4层
    root->right->left->right = new TreeNode(14);
}