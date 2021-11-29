#include "Permutations.h"
void Permute::backtracking(vector<int>& nums,vector<bool>& label,int len){
    if(path.size()==len){
        ans.push_back(path);
        return;
    }
    for(int i=0;i<len;i++){
        if(label[i]==0){
            path.push_back(nums[i]);
            label[i] = 1;
            backtracking(nums,label,len);
            label[i] = 0;
            path.pop_back();
        }
    }
};

void PermuteUnique::backtracking(vector<int>& nums,vector<bool>& label,int len){
    if(path.size()==len){
        ans.push_back(path);
        return;
    }
    int pre = -10;
    for(int i=0;i<len;i++){
        if(nums[i]==pre||label[i]==1) continue;
        pre = nums[i];
        path.push_back(nums[i]);
        label[i] = 1;
        backtracking(nums,label,len);
        label[i] = 0;
        path.pop_back();
    }
};

bool ReorderedPowerOf2::backtracking(vector<int>& nums,vector<bool>& label,int len){
    if(path.size()>=len){
        int num = 0;
        for(int i=0;i<len;i++){
            num = num*10+path[i];
        }
        if((num&(num-1))==0) return true;
    }

    int pre = -1;
    for(int i=0;i<len;i++){
        if(i>0&&nums[i]==pre||label[i]==1||(path.empty()&&nums[i]==0))
            continue;
        else{
            label[i] = 1;
            pre = nums[i];
            path.push_back(nums[i]);
            if(backtracking(nums,label,len)) return true;
            else{
                label[i] = 0;
                path.pop_back();
            }
        }
    }
    return false;
}