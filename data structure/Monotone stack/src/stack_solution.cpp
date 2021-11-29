#include "stack_solution.h"

vector<int> DailyTemperatures::dailyTemperatures(vector<int>& temperatures) {
    stack<int> s;
    int len = temperatures.size();
    vector<int> ans(len,0);
    for(int i=0;i<len;i++){
        while(!s.empty()&&temperatures[i]>temperatures[s.top()]){
            int idx = s.top();
            ans[idx] = i-idx;
            s.pop();
        }
        s.push(i);
    }
    return ans;
}

vector<int> NextGreaterElement::nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int len1 = nums1.size();
    vector<int> ans(len1,-1);
    unordered_map<int,int> Hash;
    stack<int> s;
    int len2 = nums2.size();
    for(int i=0;i<len2;i++){
        while(!s.empty()&&nums2[i]>s.top()){
            Hash.insert({s.top(),nums2[i]});
            s.pop();
        }
        s.push(nums2[i]);
    }
    for(int i=0;i<len1;i++){
        if(Hash.count(nums1[i]))
            ans[i] = Hash[nums1[i]];
    }
    return ans;
}

vector<int> NextGreaterElements2::nextGreaterElements(vector<int>& nums) {
    int len = nums.size();
    vector<int> ans(len,-1);
    stack<int> s;
    for(int i =0;i<len*2-1;i++){
        int idx = i%len;
        while(!s.empty()&&nums[idx]>nums[s.top()]){
            ans[s.top()] = nums[idx];
            s.pop();
        }
        s.push(idx);
    }
    return ans;
}

int Trap::trap(vector<int>& height) {
    stack<int> s;
    int len = height.size();
    int ans = 0;
    for(int i=0;i<len;i++){
        while(!s.empty()&&height[i]>height[s.top()]){
            int cur = s.top(); // 凹点索引
            s.pop();
            if(s.empty()) break;
            int l = s.top(); // 左侧索引
            ans = ans+(i-l-1)*(min(height[l],height[i])-height[cur]);
        }
        s.push(i);
    }
    return ans;
}

int LargestRectangleArea::largestRectangleArea(vector<int>& heights) {
    int len = heights.size();
    stack<int> s;
    vector<int> r_idx(len,len);
    vector<int> l_idx(len,-1);
    for(int i=0;i<len;i++){
        while(!s.empty()&&heights[i]<heights[s.top()]){
            r_idx[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for(int i=len-1;i>=0;i--){
        while(!s.empty()&&heights[i]<heights[s.top()]){
            l_idx[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    int ans = 0;
    for(int i=0;i<len;i++){
        ans = max(ans,(r_idx[i]-l_idx[i]-1)*heights[i]);
    }
    return ans;
}

int MaximalRectangle::maximalRectangle(vector<vector<char>>& matrix) {
    int w = matrix[0].size();
    int h = matrix.size();
    vector<vector<int>> length(h, vector<int> (w,0));
    // 整理以每一行为底的高度矩阵 length[i][j]表示第i行为底时索引为j的柱高
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(matrix[i][j]=='1'){
                length[i][j]=i==0?1:length[i-1][j]+1;
            }
        }
    }
    int ans=0;
    for(int i=0;i<h;i++){
        stack<int> s;
        vector<int> r_idx(w,w);
        vector<int> l_idx(w,-1);
        // 计算左右凹索引矩阵
        for(int j=0;j<w;j++){
            while(!s.empty()&&length[i][j]<length[i][s.top()]){
                r_idx[s.top()] = j;
                s.pop();
            }
            s.push(j);
        }
        while(!s.empty()) s.pop();
        for(int j=w-1;j>=0;j--){
            while(!s.empty()&&length[i][j]<length[i][s.top()]){
                l_idx[s.top()] = j;
                s.pop();
            }
            s.push(i);
        }
        for(int j=0;j<w;j++){
            ans = max(ans,(r_idx[j]-l_idx[j]-1)*length[i][j]);
        }
    }
    return ans;
}