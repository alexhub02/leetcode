#ifndef BACK_TRACKING_PERMUTATIONS_H
#define BACK_TRACKING_PERMUTATIONS_H
#include <iostream>
using namespace std;
#include<unordered_map>
#include<unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
/*
 * 目录
 * lc_46 全排列
 * lc_47 全排列II
 * lc_869 重新排序得到2的幂
 */
class Permute {
private:
    vector<int> path;
    vector<vector<int>> ans;
public:
    void backtracking(vector<int>& nums,vector<bool>& label,int len);
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> label(nums.size(),0);
        backtracking(nums,label,nums.size());
        return ans;
    }
}; // lc_46 全排列

class PermuteUnique {
private:
    vector<int> path;
    vector<vector<int>> ans;
public:
    void backtracking(vector<int>& nums,vector<bool>& label,int len);
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> label(nums.size(),0);
        backtracking(nums,label,nums.size());
        return ans;
    }
}; // lc_47 全排列II

class ReorderedPowerOf2 {
private:
    vector<int> nums;
    vector<int> path;
public:
    bool backtracking(vector<int>& nums,vector<bool>& label,int len);
    bool reorderedPowerOf2(int n) {
        while(n>0){
            nums.push_back(n%10);
            n /= 10;
        }
        int len = nums.size();
        vector<bool> label(len,0);
        sort(nums.begin(),nums.end(),less<int>());
        if(backtracking(nums,label,len)) return true;
        return false;
    }
}; // lc_869 重新排序得到2的幂
#endif //BACK_TRACKING_PERMUTATIONS_H
