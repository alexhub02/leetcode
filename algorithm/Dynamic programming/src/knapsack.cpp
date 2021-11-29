#include "knapsack.h"

int Change::change(int amount, vector<int>& coins) {
    int nums=coins.size();
    vector<int> dp(amount+1,0);
    dp[0]=1;
    for(int i=0;i<nums;i++){ // 遍历硬币种类
        for(int j=coins[i];j<=amount;j++){ // 遍历价值总量
            // 计算当前的硬币最多可以用几个
            dp[j]+=dp[j-coins[i]];
        }
    }
    return dp[amount];
}

int NumSquares::numSquares(int n) {
    int nums=1;
    vector<int> elem;
    // 找到所有比n小的完全平方数
    while(nums*nums<=n){
        elem.push_back(nums*nums);
        nums++;
    }
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++) dp[i]=i;
    for(int i=1;i<elem.size();i++){ // 遍历所有完全平方元素
        for(int j=elem[i];j<=n;j++){
            dp[j]=min(dp[j],dp[j-elem[i]]+1);
        }
    }
    return dp[n];
}

bool WordBreak::wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> Hash;
    int nums = wordDict.size();
    for(int i=0;i<nums;i++){
        Hash.insert(wordDict[i]);
    }
    int len=s.size();
    vector<bool> dp(len+1,0);
    dp[0]=1;
    for(int i=1;i<=len;i++){
        for(int j=0;j<i;j++){
            if(dp[j]&&Hash.find(s.substr(j,i-j))!=Hash.end()){
                dp[i]=1;
                break;
            }
        }
    }
    return dp[len];
}