#include "one_zero_bag.h"

bool CanPartition::canPartition(vector<int>& nums) {
    int sum= accumulate(nums.begin(),nums.end(),0);
    if(sum%2==1) return false; // 特判
    int target=sum/2;
    int len=nums.size();
    vector<int> dp(target+1,0); // dp[0]主要是方便dp[1]的处理
    for(int i=0;i<len;i++){ // 遍历子集
        for(int j=target;j>=nums[i];j--) // 逆序更新dp,仅更新最大容量大于当前元素值的部分
            dp[j]=max(dp[j],dp[j-nums[i]]+nums[i]);
    }
    return dp[target]==target;
}

int LastStoneWeightII::lastStoneWeightII(vector<int>& stones) {
    int sum= accumulate(stones.begin(),stones.end(),0);
    int target=sum/2;
    int len=stones.size();
    vector<int> dp(target+1,0);
    for(int i=0;i<len;i++){ // 遍历石块
        for(int j=target;j>=stones[i];j--) // 逆序更新dp,仅更新最大容量大于当前石块重的部分
            dp[j]=max(dp[j],dp[j-stones[i]]+stones[i]);
    }
    return sum-2*dp[target];
}

int FindTargetSumWays::findTargetSumWays(vector<int>& nums, int target) {
    int sum= accumulate(nums.begin(),nums.end(),0);
    if((sum+target)%2==1||abs(sum)<abs(target)) return 0;
    int new_t=(sum+target)/2; // 取+号的部分的和
    int len=nums.size();
    vector<int> dp(new_t+1,0);
    dp[0]=1; // 不选择任何元素时为1种方案
    for(int i=0;i<len;i++){ // 遍历元素
        for(int j=new_t;j>=nums[i];j--){ // 计算和为j下的方案的数量
            // 加入第j个元素时,方案为dp[j-nums[i]]种;不加入第j个元素时,方案为dp[j]种
            dp[j]=dp[j]+dp[j-nums[i]];
        }
    }
    return dp[new_t];
}

int FindMaxForm::findMaxForm_1(vector<string>& strs, int m, int n) {
    int nums=strs.size();
    // 初始化dp数组 dp[i][j][k]表示在前i个子串中使用m个0与n个1最多可表示的字符串数量
    vector<vector<vector<int>>> dp(nums+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
    for(int i=1;i<=nums;i++){
        // 统计当前字符串中0与1的个数
        int zero_num=0;
        int one_nums=0;
        int len=strs[i-1].size();
        for(int idx=0;idx<len;idx++){
            if(strs[i-1][idx]=='0') zero_num++;
            else one_nums++;
        }
        // 开始遍历
        for(int j=0;j<=m;j++){ // 使用0的个数
            for(int k=0;k<=n;k++){ // 使用1的个数
                if(j<zero_num||k<one_nums) dp[i][j][k]=dp[i-1][j][k];
                else{
                    dp[i][j][k]=max(dp[i-1][j-zero_num][k-one_nums]+1,dp[i-1][j][k]);
                }
            }
        }
    }
    return dp[nums][m][n];
}

int FindMaxForm::findMaxForm_2(vector<string>& strs, int m, int n) {
    int nums=strs.size();
    // 初始化dp数组 dp[j][k]表示遍历至子串中使用m个0与n个1最多可表示的字符串数量
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=nums;i++){
        // 统计当前字符串中0与1的个数
        int zero_num=0;
        int len=strs[i-1].size();
        for(int idx=0;idx<len;idx++){
            if(strs[i-1][idx]=='0') zero_num++;
        }
        // 开始遍历
        for(int j=m;j>=zero_num;j--){ // 使用0的个数
            for(int k=n;k>=len-zero_num;k--){ // 使用1的个数
                dp[j][k]=max(dp[j-zero_num][k-len-zero_num]+1,dp[j][k]);
            }
        }
    }
    return dp[m][n];
}