#ifndef DYNAMIC_PROGRAMMING_STOCK_TRADING_H
#define DYNAMIC_PROGRAMMING_STOCK_TRADING_H
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
 * 买卖股票目录
 * lc_121 买卖股票的最佳时机
 * lc_122 买卖股票的最佳时机II
 * lc_123 买卖股票的最佳时机III
 * lc_188 买卖股票的最佳时机IV
 * lc_309 最佳买卖股票时机含冷冻期
 * lc_714 买卖股票的最佳时机含手续费
 */

class Solution_121 {
public:
    int maxProfit(vector<int>& prices);
}; // lc_121 买卖股票的最佳时机

class Solution_122 {
public:
    int maxProfit(vector<int>& prices);
}; // lc_122 买卖股票的最佳时机II

class Solution_123 {
public:
    int maxProfit(vector<int>& prices);
}; // lc_123 买卖股票的最佳时机III

class Solution_188 {
public:
    int maxProfit(int k, vector<int>& prices);
}; // lc_188 买卖股票的最佳时机IV

class Solution_309 {
public:
    int maxProfit(vector<int>& prices);
}; // lc_309 最佳买卖股票时机含冷冻期

class Solution_714 {
public:
    int maxProfit(vector<int>& prices, int fee);
}; // lc_714 买卖股票的最佳时机含手续费
#endif //DYNAMIC_PROGRAMMING_STOCK_TRADING_H
