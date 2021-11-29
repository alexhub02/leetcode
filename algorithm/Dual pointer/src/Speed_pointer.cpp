#include "Speed_pointer.h"

int Solution_27::removeElement1(vector<int>& nums, int val) {
    int len=nums.size();
    int l=0;
    int r=len-1;
    int ans=0;
    while(r>=0&&nums[r]==val) r--;
    while(l<=r){
        if(l==r&&nums[l]==val) break;
        if(nums[l]!=val){
            ans++;
            l++;
        }
        else if(nums[l]==val){
            nums[l]=nums[r];
            nums[r]=val;
            l++;
            while(r>=0&&nums[r]==val) r--;
            ans++;
        }
    }
    return ans;
}

int Solution_27::removeElement2(vector<int>& nums, int val) {
    int slow=0;
    int len=nums.size();
    for(int fast=0;fast<len;fast++){
        if(nums[fast]!=val) nums[slow++]=nums[fast];
    }
    return slow;
}

int Solution_26::removeDuplicates1(vector<int>& nums) {
    int slow=0;
    int fast=0;
    int len=nums.size();
    if(len<=1) return len;
    while(fast<len-1){
        nums[slow++]=nums[fast]; // 维护慢指针长度
        // 快指针移动到不重复元素处
        while(fast<len-1&&nums[fast+1]==nums[fast]) fast++;
        fast++;
    }
    if(fast==len-1&&nums[fast]!=nums[fast-1])
        nums[slow++]=nums[fast];
    return slow;
}

int Solution_26::removeDuplicates2(vector<int>& nums) {
    int slow=1;
    int fast=1;
    int len=nums.size();
    if(len<=1) return len;
    while(fast<len){
        if(nums[fast]!=nums[fast-1]){
            nums[slow++]=nums[fast];
        }
        fast++;
    }
    return slow;
}

void Solution_283::moveZeroes(vector<int>& nums) {
    int slow=0;
    int fast=0;
    int len=nums.size();
    int zeros=0;
    while(fast<len){
        if(nums[fast]!=0) nums[slow++]=nums[fast];
        else zeros++;
        fast++;
    }
    while(zeros){
        nums[len-zeros]=0;
        zeros--;
    }
}