#ifndef BACK_TRACKING_COMBINE_H
#define BACK_TRACKING_COMBINE_H
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
 * lc_77 组合问题(求组合子集)
 * lc_216 组合的和3(不重复数组不可重复使用其中数字)
 * lc_17 phone_number(双层回溯)
 * lc_39 组合的和1(不重复数组可重复使用其中数字)
 * lc_40 组合的和2(重复数组不可重复使用其中数字)
 */
class Combine {
private:
    vector<int> path;
    vector<vector<int>> ans;
public:
    void backtracking(int n,int k,int start_index);
    vector<vector<int>> combine(int n, int k){
        backtracking(n,k,1);
        return ans;
    }
}; // lc_77 组合问题

class Combine_Sum3 {
private:
    vector<vector<int>> ans;
    vector<int> path;
public:
    void backtracking(int n,int k,int start_index,int sum);
    vector<vector<int>> combinationSum3(int k, int n){
        backtracking(n,k,1,0);
        return ans;
    }
}; // lc_216 组合的和3

class Phone_number {
private:
    vector<string> ans;
    string s;
    unordered_map<char, string> Hash{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
    };

public:
    void backtracking(string &digits,int start_index);
    vector<string> letterCombinations(string digits) {
        backtracking(digits,0);
        return ans;
    }
}; // lc_17 phone_number

class Combine_Sum1 {
private:
    vector<vector<int>> ans;
    vector<int> path;
public:
    void backtracking(vector<int>& candidates,int start_index,int target);
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end(),less<int>());
        backtracking(candidates,0,target);
        return ans;
    }
}; // lc_39 组合的和1

class Combine_Sum2 {
private:
    vector<vector<int>> ans;
    vector<int> path;
public:
    void backtracking(vector<int>& candidates,int start_index,int target);
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end(),less<int>());
        backtracking(candidates,0,target);
        return ans;
    }
}; // lc_40 组合的和2
#endif //BACK_TRACKING_COMBINE_H
