#include"Stock_trading.h"



int Solution_121::maxProfit(vector<int>& prices) {
    int len=prices.size();
    vector<int> dp(len+1,0);
    int minimum_price=INT32_MAX;
    int ans=0;
    for(int i=1;i<=len;i++){
        minimum_price=min(minimum_price,prices[i-1]);
        dp[i]=prices[i-1]-minimum_price;
        ans=max(dp[i],ans);
    }
    return ans;
}

// 后续分析中dp[i][j]表示第i天结束时处于第j种状态下的最大收益
int Solution_122::maxProfit(vector<int>& prices) {
    // 有两种状态,不持有股票/持有股票
    // dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i])
    // dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i])
    int len=prices.size();
    vector<int>dp(2,0);
    dp[0]=0; // 0行表示不持有股票的最大收益
    dp[1]=-prices[0]; // 1行表示持有股票的最大收益
    for(int i=1;i<len;i++){
        vector<int> dp_new(2,0);
        dp_new[0]=max(dp[0],dp[1]+prices[i]);
        dp_new[1]=max(dp[1],dp[0]-prices[i]);
        dp=dp_new;
    }
    return dp[0];
}

int Solution_123::maxProfit(vector<int>& prices) {
    // 每天结束时一共5种状态
    // 0:未进行任何操作 1:第一次买入 2:第一次卖出 3:第二次买入 4:第二次卖出
    // 初始化时把第n次买入的都变为-prices[0]
    int len=prices.size();
    vector<int> dp(5,0);
    dp[1]=-prices[0], dp[3]=dp[1];
    for(int i=1;i<len;i++){
        dp[4]=max(dp[4],dp[3]+prices[i]);
        dp[3]=max(dp[3],dp[2]-prices[i]);
        dp[2]=max(dp[2],dp[1]+prices[i]);
        dp[1]=max(dp[1],dp[0]-prices[i]);
    }
    return dp[4];
}

int Solution_188::maxProfit(int k, vector<int>& prices) {
    // 类比上一题
    int len=prices.size();
    if(!len) return 0;
    vector<int> dp(k*2+1,0);
    for(int j=1;j<2*k+1;j=j+2){
        dp[j]=-prices[0];
    }
    for(int i=1;i<len;i++){
        for(int j=2*k;j>=1;j--){
            if(j%2==0) dp[j]=max(dp[j],dp[j-1]+prices[i]);
            else dp[j]=max(dp[j],dp[j-1]-prices[i]);
        }
    }
    return dp[2*k];
}

int Solution_309::maxProfit(vector<int>& prices) {
    // 一共三种状态
    // 0:持有股票(无冷却期) 1:不持有股票(处于冷却期) 2:不持有股票(不处于冷却期)
    // dp[i][0]=max(dp[i-1][0],dp[i-1][2]-prices[i]) 可以保持不变,也可以从2状态购入股票
    // dp[i][1]=dp[i-1][0]+prices[i] 只能从上一时刻0状态卖出得到该状态
    // dp[i][2]=max(dp[i-1][1],dp[i-1][2]) 可以继承上一时刻的状态2,也可以从上一时刻状态1得到
    int len=prices.size();
    if(len==0) return 0;
    vector<int> dp(3);
    vector<int> new_dp(3);
    dp[0]=-prices[0];
    for(int i=1;i<len;i++){
        new_dp[0]=max(dp[0],dp[2]-prices[i]);
        new_dp[1]=dp[0]+prices[i];
        new_dp[2]=max(dp[2],dp[1]);
        dp=new_dp;
    }
    return max(dp[1],dp[2]);
}

int Solution_714::maxProfit(vector<int>& prices, int fee) {
    // lc_122 买卖股票的最佳时机II的简单改版,在卖出去时考虑手续费即可
    int len=prices.size();
    vector<int>dp(2,0);
    dp[0]=0; // 0行表示不持有股票的最大收益
    dp[1]=-prices[0]; // 1行表示持有股票的最大收益
    for(int i=1;i<len;i++){
        dp[0]=max(dp[0],dp[1]+prices[i]-fee);
        dp[1]=max(dp[1],dp[0]-prices[i]);
    }
    return dp[0];
}