#include "test_func.h"

void Combine_test(){
    Combine s;
    int n = 4;
    int k = 2;
    auto ans = s.combine(n,k);
    show_vec_vec(ans);
}

void Subsets_test(){
    Subsets s;
    vector<int> nums = {1,2,3,4};
    auto ans = s.subsets(nums);
    show_vec_vec(ans);
}

void show_vec_vec(vector<vector<int>>&nums){
    cout<<"[";
    for(int i = 0;i<nums.size();i++){
        cout<<"[";
        for(int j = 0;j<nums[i].size();j++){
            cout<<nums[i][j];
            if(j!=nums[i].size()-1) cout<<","; // 如果不是最后一个elem
        }
        cout<<"]";
        if(i!=nums.size()-1) cout<<",";
    }
    cout<<"]";
}
