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

void Make_Tree3(TreeNode* root){
    // 构建一棵对称二叉树
    // 第1层
    root->val = 8;
    // 第2层
    root->left = new TreeNode(5);
    root->right = new TreeNode(5);
    // 第3层
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(4);
    // 第4层
    root->right->left->right = new TreeNode(14);
    root->left->right->left = new TreeNode(14);
}

unordered_map<int,int> Hash;
TreeNode* buildTree_re(vector<int>& preorder, vector<int>& inorder,
                       int pre_begin, int pre_end, int in_begin, int in_end){
    if(in_begin>in_end||pre_begin>pre_end) return nullptr;
    int elem = preorder[pre_begin]; // 取先序遍历中的第一个元素为根的值,并在中序遍历中对其进行定位
    int idx = Hash[elem];
    int length = idx-in_begin; // 左子树长度
    TreeNode* root = new TreeNode(elem);
    root->left = buildTree_re(preorder,inorder,
                              pre_begin+1,pre_begin+length,in_begin,idx-1);
    root->right = buildTree_re(preorder,inorder,
                               pre_begin+1+length,pre_end,idx+1,in_end);
    return root;
}

TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder){
    int end_idx = inorder.size();
    for(int i = 0;i<end_idx;i++){
        Hash.emplace(inorder[i],i);
    }
    return buildTree_re(preorder,inorder,
                        0,end_idx-1,0,end_idx-1);
}
