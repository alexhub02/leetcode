#ifndef DYNAMIC_PROGRAMMING_ONE_ZERO_BAG_H
#define DYNAMIC_PROGRAMMING_ONE_ZERO_BAG_H
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
 * 0-1背包目录
 * lc_416 分割等和子集
 * lc_1049 最后一块石头的重量II
 * lc_494 目标和
 * lc_474 一和零
 */

class CanPartition {
public:
    bool canPartition(vector<int>& nums);
}; // lc_416 分割等和子集

class LastStoneWeightII {
public:
    int lastStoneWeightII(vector<int>& stones);
}; // lc_1049 最后一块石头的重量II

class FindTargetSumWays {
public:
    int findTargetSumWays(vector<int>& nums, int target);
}; // lc_494 目标和

class FindMaxForm {
public:
    int findMaxForm_1(vector<string>& strs, int m, int n);
    int findMaxForm_2(vector<string>& strs, int m, int n); // 做了空间复杂度优化
}; // lc_474 一和零

#endif //DYNAMIC_PROGRAMMING_ONE_ZERO_BAG_H
