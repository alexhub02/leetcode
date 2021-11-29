#include "Tree.h"

void preorder_with_re(TreeNode* root){
    if(!root) return;
    cout<<root->val<<" ";
    preorder_with_re(root->left);
    preorder_with_re(root->right);
}

void preorder_without_re(TreeNode* root){
    if(!root) return;
    stack<TreeNode*> s;
    TreeNode* p = root;
    while(!s.empty()||p){
        // 若辅助栈非空或节点非空,先打印,然后压栈,再往左搜索
        while(p){
            cout<<p->val<<" ";
            s.push(p);
            p = p->left;
        }
        // 左子树遍历完毕,进入右子树
        if(!s.empty()){
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}

void inorder_with_re(TreeNode* root){
    if(!root) return;
    inorder_with_re(root->left);
    cout<<root->val<<" ";
    inorder_with_re(root->right);
}

void inorder_without_re(TreeNode* root){
    if(!root) return;
    stack<TreeNode*> s;
    TreeNode* p = root;
    while(!s.empty()||p){
        // 若辅助栈非空或节点非空,先压栈,再往左搜索
        while(p){
            s.push(p);
            p = p->left;
        }
        // 左子树遍历完毕,打印出栈节点,进入右子树
        if(!s.empty()){
            p = s.top();
            cout<<p->val<<" ";
            s.pop();
            p = p->right;
        }
    }
}

void postorder_with_re(TreeNode* root){
    if(!root) return;
    postorder_with_re(root->left);
    postorder_with_re(root->right);
    cout<<root->val<<" ";
}

void postorder_without_re(TreeNode* root){
    if(!root) return;
    stack<TreeNode*> s;
    vector<TreeNode*> inversion;
    TreeNode* p = root;
    // 若辅助栈非空或节点非空,先压栈,再往右搜索[以root->right->left]先存入inversion
    while(!s.empty()||p){
        while(p){
            s.push(p);
            inversion.push_back(p);
            p = p->right;
        }
        // 右子树遍历完毕,进入左子树
        if(!s.empty()){
            p = s.top();
            s.pop();
            p = p->left;
        }
    }
    for(int i = inversion.size()-1;i>=0;i--){
        cout<<inversion[i]->val<<" ";
    }
}

void postorder_without_re2(TreeNode* root){
    // 当前节点为叶子节点时或者上一个访问节点为当前节点的右子节点时进行打印
    if(!root) return;
    stack<TreeNode*> s;
    TreeNode* p = root;
    TreeNode* pre = nullptr;
    // 若辅助栈非空或节点非空,先压栈,再往左搜索
    while(!s.empty()||p){
        while(p){
            s.push(p);
            p = p->left;
        }
        if(!s.empty()){
            // 此时的p->left = nullptr
            p = s.top();
            // 叶子节点以及刚访问完右子节点的节点可以访问
            if(!p->right||pre==p->right){
                s.pop();
                pre = p;
                cout<<p->val<<" ";
                p = nullptr;// 关键操作
                // 直接进入栈的弹出阶段，因为但凡在栈中的节点，它们的左子节点都肯定被经过且已放入栈中
            }
            else{
                p = p->right;
            }
        }
    }
}

void level_order(TreeNode* root){
    if(!root) return;
    queue<TreeNode*> q;
    TreeNode *p = root;
    q.push(p);
    while(!q.empty()){
        p = q.front();
        q.pop();
        cout<<p->val<<" ";
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
}