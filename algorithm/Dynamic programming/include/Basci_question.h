#ifndef DYNAMIC_PROGRAMMING_BASCI_QUESTION_H
#define DYNAMIC_PROGRAMMING_BASCI_QUESTION_H
#include <iostream>
using namespace std;
#include<unordered_map>
#include<unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
/*
 * 简单动态规划目录
 * lc_70 爬楼梯
 * lc_746 使用最小花费爬楼梯
 * lc_62 不同路径
 * lc_63 不同路径II
 * lc_343 整数拆分
 * lc_96 不同的二叉搜索树
 */

class ClimbStairs {
public:
    int climbStairs_1(int n);
    int climbStairs_2(int n); // 做空间优化 o(n)->o(1)
}; // lc_70 爬楼梯

class MinCostClimbingStairs {
public:
    int minCostClimbingStairs_1(vector<int>& cost);
    int minCostClimbingStairs_2(vector<int>& cost); // 做空间优化 o(n)->o(1)
}; // lc_746 使用最小花费爬楼梯

class UniquePaths {
public:
    int uniquePaths_1(int m, int n);
    int uniquePaths_2(int m, int n); // 做空间优化 o(mn)->o(min(m,n))
}; // lc_62 不同路径

class UniquePathsWithObstacles {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
}; // lc_63 不同路径II

class IntegerBreak {
public:
    int integerBreak(int n);
}; // lc_343 整数拆分

class NumTrees {
public:
    int numTrees(int n);
}; // lc_96 不同的二叉搜索树
#endif //DYNAMIC_PROGRAMMING_BASCI_QUESTION_H
