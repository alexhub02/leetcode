#ifndef BACK_TRACKING_SUBSETS_H
#define BACK_TRACKING_SUBSETS_H
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
 * lc_78 子集I
 * lc_90 子集II
 */
class Subsets {
private:
    vector<int> path;
    vector<vector<int>> ans;
public:
    void backtracking(vector<int>& nums,int start_index,int len);
    vector<vector<int>> subsets(vector<int>& nums){
        int len = nums.size()-1;
        backtracking(nums,0,len);
        return ans;
    };
}; // lc_78 子集I

class SubsetsWithDup {
private:
    vector<int> path;
    vector<vector<int>> ans;
public:
    void backtracking(vector<int>& nums,int start_index,int len);
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int len = nums.size()-1;
        sort(nums.begin(),nums.end(),less<int>());
        backtracking(nums,0,len);
        return ans;
    }
}; // lc_90 子集II

#endif //BACK_TRACKING_SUBSETS_H
