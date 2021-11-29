#include "Subsets.h"

void Subsets::backtracking(vector<int>& nums,int start_index,int len){
    ans.push_back(path);
    if(start_index>len) return;
    for(int i=start_index;i<=len;i++){
        path.push_back(nums[i]);
        backtracking(nums,i+1,len);
        path.pop_back();
    }
}

void SubsetsWithDup::backtracking(vector<int>& nums,int start_index,int len){
    ans.push_back(path);
    if(start_index>len) return;
    int pre;
    for(int i=start_index;i<=len;i++){
        if(i>start_index&&nums[i]==pre) continue; // 去重
        path.push_back(nums[i]);
        backtracking(nums,i+1,len);
        path.pop_back();
        pre = nums[i];
    }
}
