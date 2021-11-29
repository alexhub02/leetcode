#include "BST.h"

TreeNode* FindMin(TreeNode* root){
    if(!root) return nullptr;
    TreeNode* p =root;
    while(p->left){
        p = p->left;
    }
    return p;
}
TreeNode* FindMax(TreeNode* root){
    if(!root) return nullptr;
    TreeNode* p =root;
    while(p->right){
        p = p->right;
    }
    return p;
}

TreeNode* Insert(TreeNode* root,int elem){
    if(!root){
        root = new TreeNode(elem);
    }
    if(elem>root->val)
        root->right = Insert(root->right,elem);
    else if(elem<root->val)
        root->left = Insert(root->left,elem);
    return root;
}

TreeNode* Delete(TreeNode* root,int elem){
    // 如果待删除的节点是叶子节点,直接删除;
    // 如果待删除的节点有且只有一个节点非空,直接删除,后续子树补位;
    // 如果待删除的节点左右子树均不空,用其左子树的最大值或者右子树的最小值代替;
    // 同时在对应的左/右子树中删除节点
    TreeNode* p;
    if(!root){
        cout<<"Node does not exist!"<<endl;
        return root;
    }
    if(elem>root->val) root->right = Delete(root->right,elem);
    else if(elem<root->val) root->left = Delete(root->left,elem);
    else{
        // 找到需要删除的节点
        if(root->left&&root->right){
            // 若左右节点均存在,用右子树的最小值来代替
            p = FindMin(root->right);
            root->val = p->val;
            // 在右子树中删除对应的节点
            root->right = Delete(root->right,root->val);
        }
        else{
            // 无子节点或者仅有一个子节点
            p = root;
            if(!root->left&&!root->right)
                root = nullptr;
            else if(root->left)
                root = root->left;
            else
                root = root->right;
            delete p;
        }
    }
    return root;
}