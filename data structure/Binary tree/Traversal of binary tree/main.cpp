#include <iostream>
#include "Tree.h"
#include "BST.h"
void Traversal(){
    TreeNode * root = new TreeNode();
    Make_Tree1(root);

    cout<<"pre_with_re: ";
    preorder_with_re(root);
    cout<<endl;
    cout<<"pre_without_re: ";
    preorder_without_re(root);
    cout<<endl;

    cout<<"in_with_re: ";
    inorder_with_re(root);
    cout<<endl;
    cout<<"in_without_re: ";
    inorder_without_re(root);
    cout<<endl;

    cout<<"post_with_re: ";
    postorder_with_re(root);
    cout<<endl;
    cout<<"post_without_re: ";
    postorder_without_re(root);
    cout<<endl;
    cout<<"post_without_re2: ";
    postorder_without_re2(root);
    cout<<endl;

    cout<<"level_order: ";
    level_order(root);
    cout<<endl;

}

void BST_operation(){
    TreeNode* root = new TreeNode();
    Make_Tree2(root);
    cout<<"level_order of BST: ";
    level_order(root);
    cout<<endl;
    cout<<"Max elem of BST: "<<FindMax(root)->val<<endl;
    cout<<"Min elem of BST: "<<FindMin(root)->val<<endl;
    Insert(root,13);
    cout<<"After insert step, the level_order of BST: ";
    level_order(root);
    cout<<endl;
    Delete(root,7);
    cout<<"After delete step, the level_order of BST: ";
    level_order(root);
    cout<<endl;
}
int main() {
//    Traversal();
    BST_operation();
    return 0;
}
