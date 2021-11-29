#ifndef DYNAMIC_PROGRAMMING_ROB_H
#define DYNAMIC_PROGRAMMING_ROB_H
#include <iostream>
using namespace std;
#include<unordered_map>
#include<unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
/*
 * 打家劫舍目录
 * lc_198 打家劫舍
 * lc_213 打家劫舍II
 * lc_337 打家劫舍III
 */

class Rob1 {
public:
    int rob(vector<int>& nums);
}; // lc_198 打家劫舍

class Rob2 {
public:
    int total_value(vector<int>& nums, int start,int end);
    int rob(vector<int>& nums);
}; // lc_213 打家劫舍II

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Rob3 {
public:
    unordered_map<TreeNode*, int> val_map;
    int rob_1(TreeNode* root); // 纯递归,会涉及多次重复计算
    int rob_2(TreeNode* root); // 记忆化递归,不涉及重复计算
    vector<int>rob_Tree(TreeNode* root); // 动态规划
    int rob_3(TreeNode* root) {
        vector<int> ans= rob_Tree(root);
        return max(ans[0],ans[1]);
    }
}; // lc_337 打家劫舍III
#endif //DYNAMIC_PROGRAMMING_ROB_H
