#ifndef BINARY_SEARCH_BINARY_SEARCH_H
#define BINARY_SEARCH_BINARY_SEARCH_H
#include <iostream>
using namespace std;
#include<unordered_map>
#include<unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include "math.h"
#include <stdlib.h>

/*
 * 目录
 * lc_704 二分查找
 * lc_35 搜索插入位置
 * lc_34 在排序数组中查找元素的第一个和最后一个位置
 * lc_162 寻找峰值
 * lc_33 搜索旋转排序数组
 * lc_81 搜索旋转排序数组II
 * lc_153 寻找旋转排序数组中的最小值
 * lc_154 寻找旋转排序数组中的最小值II
 * lc_74 搜索二维矩阵
 * lc_240 搜索二维矩阵II
 */

class Search {
public:
    int search(vector<int>& nums, int target);
}; // lc_704 二分查找

class SearchInsert {
public:
    int searchInsert(vector<int>& nums, int target);
}; // lc_35 搜索插入位置

class SearchRange {
public:
    vector<int> searchRange(vector<int>& nums, int target);
}; // lc_34 在排序数组中查找元素的第一个和最后一个位置

class FindPeakElement {
public:
    int findPeakElement(vector<int>& nums);
}; // lc_162 寻找峰值

class Rotate_search {
public:
    int search(vector<int>& nums, int target);
}; // lc_33 搜索旋转排序数组

class Rotate_search2 {
public:
    bool search(vector<int>& nums, int target);
}; // lc_81 搜索旋转排序数组II

class FindMin {
public:
    int findMin(vector<int>& nums);
}; // lc_153 寻找旋转排序数组中的最小值

class FindMin2 {
public:
    int findMin(vector<int>& nums);
}; // lc_154 寻找旋转排序数组中的最小值II

class SearchMatrix {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target);
}; // lc_74 搜索二维矩阵

class SearchMatrix2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target);
}; // lc_240 搜索二维矩阵II
#endif //BINARY_SEARCH_BINARY_SEARCH_H
