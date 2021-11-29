#ifndef DYNAMIC_PROGRAMMING_KNAPSACK_H
#define DYNAMIC_PROGRAMMING_KNAPSACK_H
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
 * 完全背包目录
 * lc_518 零钱兑换II
 * lc_279 完全平方数
 * lc_139 单词拆分
 */
class Change {
public:
    int change(int amount, vector<int>& coins);
}; // lc_518 零钱兑换II

class NumSquares {
public:
    int numSquares(int n);
}; // lc_279 完全平方数

class WordBreak {
public:
    bool wordBreak(string s, vector<string>& wordDict);
}; // lc_139 单词拆分
#endif //DYNAMIC_PROGRAMMING_KNAPSACK_H
