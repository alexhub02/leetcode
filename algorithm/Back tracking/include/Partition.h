#include <iostream>
using namespace std;
#include<unordered_map>
#include<unordered_set>
#include <set>
#include <stack>
#include <queue>
#ifndef BACK_TRACKING_PARTITION_H
#define BACK_TRACKING_PARTITION_H
/*
 * 目录
 * lc_131 分割回文串(纵向更新起点,横向更新步长)
 * lc_93 复原ip地址(深度最大为4,横向最大为3)
 */
class Partition {
private:
    vector<vector<string>> ans;
    vector<string> path;
public:
    bool is_Palindrome(string& s);
    void backtracking(string &s,int start_index,int len);
    vector<vector<string>> partition(string s) {
        backtracking(s,0,s.size());
        return ans;
    }
}; // lc_131 分割回文串

class RestoreIpAddresses {
private:
    vector<string> ans;
    vector<string> path;
public:
    void backtracking(string &s,int start_index,int len);
    vector<string> restoreIpAddresses(string s) {
        backtracking(s,0,s.size());
        return ans;
    }
}; // lc_93 复原ip地址

#endif //BACK_TRACKING_PARTITION_H
