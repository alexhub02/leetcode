#ifndef TRAVERSAL_OF_BINARY_TREE_BST_H
#define TRAVERSAL_OF_BINARY_TREE_BST_H
#include "Tree.h"
TreeNode* FindMin(TreeNode* root); // 找到最小值并返回地址
TreeNode* FindMax(TreeNode* root); // 找到最大值并返回地址
TreeNode* Insert(TreeNode* root,int elem); // 插入元素,返回根节点的地址
TreeNode* Delete(TreeNode* root,int elem); // 删除元素,返回根节点的地址
#endif //TRAVERSAL_OF_BINARY_TREE_BST_H
