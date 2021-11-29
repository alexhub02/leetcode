#include "bag.h"

int one_zero_2(){
/*
 * 有重量为1,3,4的物品各一件,其价值分别为15,20,30;背包最大容量为4,计算背包能承载的最大价值量
 */
    vector<int> weight {1, 3, 4}; // 物品的重量
    vector<int> value {15, 20, 30}; // 物品的价值
    int bagWeight = 4; // 背包最大承载重量
    vector<vector<int>> dp(weight.size(), vector<int>(bagWeight + 1, 0));
    // 初始化,仅放第一个物品时,更新该行的最大价值
    for(int j=weight[0];j<=bagWeight;j++){
        dp[0][j]=value[0];
    }
    // 动态规划
    for(int i=1;i<weight.size();i++){ // 遍历物品
        for(int j=1;j<=bagWeight;j++){ // 遍历重量
            if(j<=weight[i]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
            // 如果不放物品i,那么dp[i][j]=dp[i-1][j]
            // 如果放物品i,那么必须要能放得下物品i,故之前可用的最大容量为j-weight[i]
            // 所以之前的最大价值为dp[i-1][j-weight[i]],加入i后的最大价值即加上value[i]
        }
    }
    return dp[weight.size()-1][bagWeight];
} // 背包问题

int one_zero_1(){
/*
 * 有重量为1,3,4的物品各一件,其价值分别为15,20,30;背包最大容量为4,计算背包能承载的最大价值量
 */
    vector<int> weight {1, 3, 4}; // 物品的重量
    vector<int> value {15, 20, 30}; // 物品的价值
    int bagWeight = 4; // 背包最大承载重量
    vector<int> dp (bagWeight + 1, 0);
    // 初始化,仅放第一个物品时,更新该行的最大价值
    for(int j=weight[0];j<=bagWeight;j++){
        dp[j]=value[0];
    }
    // 动态规划
    for(int i=1;i<weight.size();i++){ // 遍历物品
        for(int j=bagWeight;j>=1;j--){ // 倒叙遍历重量
            if(j>=weight[i]) dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    return dp[bagWeight];
} // 背包问题

int complete_2(){
/*
 * 有重量为1,3,4的物品无数件,其价值分别为15,20,30;背包最大容量为4,计算背包能承载的最大价值量
 */
    vector<int> weight {1, 3, 4}; // 物品的重量
    vector<int> value {15, 20, 30}; // 物品的价值
    int bagWeight = 4; // 背包最大承载重量
    vector<int> dp(bagWeight + 1, 0);
    for(int i=0;i<weight.size();i++){ // 遍历物品
        for(int j=weight[i];j<=bagWeight;j++){ // 遍历容量
            dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    return dp[weight.size()];
} // 完全背包问题,先遍历物品再遍历容量

int complete_1(){
/*
 * 有重量为1,3,4的物品无数件,其价值分别为15,20,30;背包最大容量为4,计算背包能承载的最大价值量
 */
    vector<int> weight {1, 3, 4}; // 物品的重量
    vector<int> value {15, 20, 30}; // 物品的价值
    int bagWeight = 4; // 背包最大承载重量
    vector<int> dp(bagWeight + 1, 0);
    for(int j=0;j<=bagWeight;j++){ // 遍历容量
        for(int i=0;i<weight.size();i++){ // 遍历物品
            if(j-weight[i]>=0) dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    return dp[weight.size()];
} // 完全背包问题,先遍历容量再遍历物品
