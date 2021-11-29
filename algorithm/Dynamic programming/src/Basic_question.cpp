#include "Basci_question.h"

int ClimbStairs::climbStairs_1(int n) {
    if(n==1) return 1;
    vector<int> dp(n,0);
    dp[0]=1;
    dp[1]=2;
    for(int i=2;i<n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n-1];
}

int ClimbStairs::climbStairs_2(int n) {
    if(n==1) return 1;
    vector<int> dp(2,0);
    dp[0]=1;
    dp[1]=2;
    for(int i=2;i<n;i++){
        int temp=dp[1];
        dp[1]=dp[1]+dp[0];
        dp[0]=temp;
    }
    return dp[1];
}

int MinCostClimbingStairs::minCostClimbingStairs_1(vector<int>& cost) {
    int len=cost.size();
    vector<int> dp(len, 0);
    dp[0]=cost[0];
    dp[1]=min(cost[0], cost[1]);
    for(int i=2;i<len;i++){
        dp[i] = min(dp[i - 1], dp[i]) + cost[i];
    }
    return dp[len - 1];
}

int MinCostClimbingStairs::minCostClimbingStairs_2(vector<int>& cost) {
    int len=cost.size();
    vector<int> dp(2, 0);
    dp[0]=cost[0];
    dp[1]=cost[1];
    for(int i=2;i<len;i++){
        int temp = dp[1];
        dp[1] = min(dp[0], dp[1]) + cost[i];
        dp[0] = temp;
    }
    return min(dp[0], dp[1]);
}

int UniquePaths::uniquePaths_1(int m, int n) {
    if(m==1||n==1) return 1;
    vector<vector<int>> dp(m,vector<int>(n,0));
    for(int i=0;i<n;i++) dp[0][i]=1;
    for(int i=0;i<m;i++) dp[i][0]=1;
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int UniquePaths::uniquePaths_2(int m, int n) {
    if(m==1||n==1) return 1;
    vector<int> dp(min(m,n),1);
    if(m>=n){ // 行数大于列数,则以每行为单位减少空间开销
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[j]=dp[j-1]+dp[j];
            }
        }
        return dp[n-1];
    }
    // 行数小于列数,则以每列为单位减少空间开销
    for(int j=1;j<n;j++){
        for(int i=1;i<m;i++){
            dp[i]=dp[i-1]+dp[i];
        }
    }
    return dp[m-1];
}

int UniquePathsWithObstacles::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    for(int i=0;i<n;i++){
        if(obstacleGrid[0][i]==1) break;
        dp[0][i]=1;
    }
    for(int i=0;i<m;i++){
        if(obstacleGrid[i][0]==1) break;
        dp[i][0]=1;
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(obstacleGrid[i][j]!=1) dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int IntegerBreak::integerBreak(int n) {
    vector<int> dp(n+1,0); // dp[n]表示将n拆分后的积的最大值,dp[0]是多余的
    dp[1]=1; // n=1时取1
    dp[2]=1; // n=2时取1 2=1+1 1*1=1
    for(int i=3;i<=n;i++){
        for(int j=1;j<=i-1;j++){ // 遍历每一种划分方式
            // j*dp[i-j]表示对于i-j还需要继续划分,j*(1-j)表明无需继续划分
            dp[i]=max(dp[i],max(j*(i-j),j*dp[i-j]));
        }
    }
    return dp[n];
}

int NumTrees::numTrees(int n) {
    vector<int> dp(n+1,1); // dp[n]表示n个节点的二叉搜索树的数量
    for(int i=2;i<=n;i++){
        int sum=0;
        for(int root=1;root<=i;root++){ // 对以root作为根节点的二叉搜索树的数量进行求和
            sum =sum+dp[root-1]*dp[i-root];
        }
        dp[i]=sum;
    }
    return dp[n];
}
