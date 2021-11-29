#ifndef DUAL_POINTER_SPEED_POINTER_H
#define DUAL_POINTER_SPEED_POINTER_H
#include <iostream>
using namespace std;
#include<unordered_map>
#include<unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
/*
 * 快慢指针目录
 * lc_27 移除元素
 * lc_26 删除排序数组中的重复项
 * lc_283 移动零
 */
class Solution_27 {
public:
    int removeElement1(vector<int>& nums, int val); // 反向指针
    int removeElement2(vector<int>& nums, int val); // 快慢指针
}; // lc_27 移除元素

class Solution_26 {
public:
    int removeDuplicates1(vector<int>& nums); // 快慢指针,通过判断当前与之后的字符是否相同去重
    int removeDuplicates2(vector<int>& nums); // 快慢指针,通过判断当前与之前的字符是否相同去重
}; // lc_26 删除排序数组中的重复项

class Solution_283 {
public:
    void moveZeroes(vector<int>& nums); // 快慢指针
}; // lc_283 移动零
#endif //DUAL_POINTER_SPEED_POINTER_H
