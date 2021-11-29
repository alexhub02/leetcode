#include "Binary_search.h"

int Search::search(vector<int>& nums, int target) {
    int l = 0,r = nums.size()-1;
    while(l<=r){
        int mid = (r-l)/2+l;
        int num = nums[mid];
        if(num==target) return mid;
        else if(num>target) r = mid-1;
        else l = mid+1;
    }
    return -1;
}

int SearchInsert::searchInsert(vector<int>& nums, int target) {
    int len=nums.size()-1;
    int l=0,r=len;
    int mid;
    while(l<=r){
        mid=l+(r-l)/2;
        if(nums[mid]==target) break;
        else if(nums[mid]>target){ // mid处过大
            if(mid==0||nums[mid-1]<target) return mid;
            r=mid-1;
        }
        else if(nums[mid]<target){ // mid处过小
            if(mid==len||nums[mid+1]>target) return mid+1;
            l=mid+1;
        }
    }
    return mid;
}

vector<int> SearchRange::searchRange(vector<int>& nums, int target) {
    int len=nums.size();
    if(len==0) return {-1,-1};
    int l=0,r=len-1;
    int mid;
    while(l<=r){ // 先找右边界
        mid=(r-l)/2+l;
        if(nums[mid]>target) r=mid-1;
        else {
            if(mid==len-1||nums[mid+1]>target)
                break;
            l=mid+1;
        }
    }
    if(nums[mid]!=target) return {-1,-1};
    int R=mid;
    l=0,r=len-1;
    while(l<=r){ // 再找左边界
        mid=(r-l)/2+l;
        if(nums[mid]<target) l=mid+1;
        else {
            if(mid==0||nums[mid-1]<target)
                break;
            r=mid-1;
        }
    }
    if(nums[mid]!=target) return {-1,-1};
    return {mid,R};
}

int FindPeakElement::findPeakElement(vector<int>& nums) {
    int len=nums.size();
    int l=1,r=len-2;
    if(len<2||nums[0]>nums[1]) return 0;
    if(nums[r+1]>nums[r]) return r+1;
    int mid;
    while(l<=r){
        mid=l+(r-l)/2;
        if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1]) return mid;
        else if(nums[mid]>nums[mid-1]){
            // 在上升部分
            l=mid+1;
        }
        else r=mid-1;
    }
    return 0;
}

int Rotate_search::search(vector<int>& nums, int target) {
    int len =nums.size()-1;
    int l=0,r=len;
    int mid;
    while(l<=r){
        mid=l+(r-l)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]>=nums[0]){ // 若[0,mid]为单调增
            if(target<nums[mid]&&target>=nums[0]) r=mid-1; // 若target位于[0,mid]区间内
            else l=mid+1; // target不在[0,mid]区间内
        }
        else{ // 若0-mid不为单调增,则[mid,len]为单调增
            if(target>nums[mid]&&target<=nums[len]) l=mid+1; // 若target位于[mid,len]区间内
            else r=mid-1; // 若target不位于[mid,len]区间内
        }
    }
    return -1;
}

bool Rotate_search2::search(vector<int>& nums, int target) {
    int len =nums.size()-1;
    int l=0,r=len;
    int mid;
    while(l<=r){
        mid=l+(r-l)/2;
        if(nums[mid]==target) return true;
        if(nums[mid]==nums[l]&&nums[mid]==nums[r]){ // 缩小区间
            l++;
            r--;
        }
        else{
            if(nums[mid]>=nums[l]){ // 若[l,mid]单调不减
                if(target<nums[mid]&&target>=nums[l]) r=mid-1; // 若target位于[l,mid]区间内
                else l=mid+1; // target不在[l,mid]区间内
            }
            else{ // [l,mid]单调不减不成立,则[mid,r]为单调不减
                if(target>nums[mid]&&target<=nums[r]) l=mid+1; // 若target位于[mid,r]区间内
                else r=mid-1; // target不在[mid,r]区间内
            }
        }
    }
    return false;
}

int FindMin::findMin(vector<int>& nums) {
    int len =nums.size()-1;
    int l=0,r=len;
    int mid;
    while(l<=r){
        mid=l+(r-l)/2;
        if(nums[l]<=nums[r]) return nums[l];
        if(nums[mid]>=nums[l]){ // 若[l,mid]为单调增,那么最小值应该在[mid,r]之间
            l=mid+1;
        }
        else{ // 若[l,mid]不为单调增,那么最小值应该在[l,mid]之间
            l=l+1;
            r=mid;
        }
    }
    return 0;
}

int FindMin2::findMin(vector<int>& nums) {
    int len =nums.size()-1;
    int l=0,r=len;
    int mid;
    while(l<=r){
        mid=l+(r-l)/2;
        if(nums[l]<nums[r]||l==r) return nums[l];
        else if(nums[l]==nums[r]) r--;
        else if(nums[l]>nums[r]){ // [l,r]单调不减不成立
            if(nums[mid]>=nums[l]) l=mid+1; // [l,mid]单调不减成立
            else if(nums[mid]<nums[l]){ // [l,mid]单调不减不成立,则最小值在[l,mid]内
                r=mid;
                l++; // l处不取最小值
            }
        }
    }
    return 0;
}

bool SearchMatrix::searchMatrix(vector<vector<int>>& matrix, int target) {
    int h=matrix.size();
    int w=matrix[0].size();
    int l=0,r=h-1;
    int mid;
    while(l<=r){ // 先定位行
        mid=l+(r-l)/2;
        if(matrix[mid][0]==target||matrix[mid][w-1]==target) return true;
        else if(matrix[mid][0]<target&&matrix[mid][w-1]>target) break;
        else if(matrix[mid][0]>target) r=mid-1;
        else l=mid+1;
    }
    if(matrix[mid][0]>target||matrix[mid][w-1]<target) return false;
    int x=mid;
    l=0,r=w-1;
    while(l<=r){ // 再定位列
        mid=l+(r-l)/2;
        if(matrix[x][mid]==target) return true;
        else if(matrix[x][mid]>target) r=mid-1;
        else l=mid+1;
    }
    return false;
}

bool SearchMatrix2::searchMatrix(vector<vector<int>>& matrix, int target) {
    int w=matrix[0].size(),h=matrix.size();
    int x=0,y=w-1;
    while(x<=h-1&&y>=0){
        if(matrix[x][y]==target) return true;
        else if(matrix[x][y]>target) y--;
        else x++;
    }
    return false;
}