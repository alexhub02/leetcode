#include "Combine.h"

void Combine::backtracking(int n,int k,int start_index){
    if(path.size()==k){
        ans.push_back(path);
        return;
    }
    if(path.size()+n-start_index+1<k){
        // 剪枝操作
        return;
    }
    for(int i = start_index;i<=n;i++){
        path.push_back(i);
        backtracking(n,k,i+1);
        path.pop_back(); // 撤销操作
    }
}

void Combine_Sum3::backtracking(int n,int k,int start_index,int sum){
    if(path.size()==k&&sum==n){
        ans.push_back(path);
        return;
    }
    if(sum>=n||path.size()>=k){
        return;
    }
    for(int i=start_index;i<=9;i++){
        path.push_back(i);
        backtracking(n,k,start_index+1,sum+i);
        path.pop_back();
        sum = sum-i;
    }
}

void Phone_number::backtracking(string &digits,int start_index){
    if(digits.size()==s.size()&&!s.empty()){
        ans.push_back(s);
        return;
    }
    for(int i=start_index;i<digits.size();i++){
        for(int j =0;j<Hash[digits[i]].size();j++){
            s = s+Hash[digits[i]][j];
            backtracking(digits,i+1);
            s.pop_back();
        }
    }
}

void Combine_Sum1::backtracking(vector<int>& candidates,int start_index,int target){
    if(target==0){
        ans.push_back(path);
        return;
    }
    if(target<0) return;
    for(int i=start_index;i<candidates.size();i++){
        if(target-candidates[i]<0) return; // 考虑剪枝,如果当前已经过大则不用考虑后续
        path.push_back(candidates[i]);
        backtracking(candidates,i,target-candidates[i]);
        path.pop_back();
    }
}

void Combine_Sum2::backtracking(vector<int>& candidates,int start_index,int target){
    if(target==0){
        ans.push_back(path);
        return;
    }

    for(int i=start_index;i<candidates.size();i++){
        if(i>start_index&&candidates[i]==candidates[i-1]) continue; // 去重
        if(target-candidates[i]<0) return; //剪枝
        path.push_back(candidates[i]);
        backtracking(candidates,i+1,target-candidates[i]);
        path.pop_back();
    }
}