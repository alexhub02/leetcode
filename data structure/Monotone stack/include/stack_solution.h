#ifndef MONOTONE_STACK_STACK_SOLUTION_H
#define MONOTONE_STACK_STACK_SOLUTION_H
#include <iostream>
using namespace std;
#include<unordered_map>
#include<unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
// 单调栈题解
/*
 * 目录
 * lc_739 每日温度
 * lc_496 下一个更大的元素
 * lc_503 下一个更大的元素II
 * lc_42 接雨水
 * lc_84 柱状图中最大的矩形
 * lc_85 最大矩形
 */

class DailyTemperatures {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures);
}; // lc_739 每日温度

class NextGreaterElement {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2);
}; // lc_496 下一个更大的元素

class NextGreaterElements2 {
public:
    vector<int> nextGreaterElements(vector<int>& nums);
}; // lc_503 下一个更大的元素II

class Trap {
public:
    int trap(vector<int>& height);
}; // lc_42 接雨水

class LargestRectangleArea {
public:
    int largestRectangleArea(vector<int>& heights);
}; // lc_84 柱状图中最大的矩形

class MaximalRectangle {
public:
    int maximalRectangle(vector<vector<char>>& matrix);
}; // lc_85 最大矩形
#endif //MONOTONE_STACK_STACK_SOLUTION_H
