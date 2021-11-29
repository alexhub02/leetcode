#include <iostream>
#include "Tree.h"
#include "Recur.h"
void test01(){
    // 最大深度
    TreeNode * root = new TreeNode();
    Make_Tree3(root);
    cout<<"preorder: ";
    preorder_with_re(root);
    cout<<endl;
    cout<<"max_depth(down_top):"<<max_depth_down_top(root)<<endl;
    cout<<"max_depth(top_down):"<<max_depth_top_down(root)<<endl;
}

void test02(){
    // 对称二叉树
    TreeNode * root = new TreeNode();
    Make_Tree3(root); // 1,2是非对称二叉树,3是对称二叉树
    cout<<"without re: "<<isSymmetric(root)<<endl;
    cout<<"with re: "<<isSymmetric_re(root)<<endl;
}

void test03(){
    // 根据前序与中序构建二叉树
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = buildTree(preorder,inorder);
    level_order(root);
}
int main() {
//    test01();
//    test02();
    test03();
    return 0;
}
