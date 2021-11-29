#include "Rob.h"

int Rob1::rob(vector<int>& nums) {
    // dp[i]=max(dp[i-1],dp[i-2]+val[i])
    int len=nums.size();
    if(len==1) return nums[0];
    vector<int> dp(2,0);
    dp[1]=nums[0];
    for(int i=1;i<len;i++){
        int temp=dp[1];
        dp[1]=max(dp[1],dp[0]+nums[i-1]);
        dp[0]=temp;
    }
    return max(dp[0],dp[1]);
}


int Rob2::total_value(vector<int>& nums, int start,int end){
    // start/end是房间号的闭区间
    int len=end-start+1;
    if(len==1) return nums[start]; // end=start
    vector<int> dp(2,0);
    dp[1]=nums[start];
    for(int i=start+1;i<=end;i++){
        int temp=dp[1];
        dp[1]=max(dp[1],dp[0]+nums[i]);
        dp[0]=temp;
    }
    return max(dp[0],dp[1]);
}
int Rob2::rob(vector<int>& nums) {
    int len=nums.size();
    if(len==1) return nums[0]; // 只有一间房
    int val1=total_value(nums,0,len-2); // 从第1间房开始遍历到第n-1间
    int val2=total_value(nums,1,len-1); // 从第2间房开始遍历到第n间
    return max(val1,val2);
}

int Rob3::rob_1(TreeNode* root) {
    // 纯递归,会涉及多次重复计算
    if(!root) return 0;
    if(root->left==nullptr&&root->right==nullptr) return root->val;

    // 打劫父节点,则不可打劫子节点
    int val1=root->val;
    if(root->left) val1=val1+rob_1(root->left->left)+rob_1(root->left->right);
    if(root->right) val1=val1+rob_1(root->right->left)+rob_1(root->right->right);

    // 不打劫父节点,则可打劫子节点
    int val2=rob_1(root->left)+rob_1(root->right);
    return max(val1,val2);
}

int Rob3::rob_2(TreeNode* root) {
    // 记忆化递归,不涉及重复计算
    if(!root) return 0;
    if(root->left==nullptr&&root->right==nullptr){
        val_map[root]= root->val;
        val_map[root];
    }
    if(val_map.find(root)!=val_map.end()) return val_map[root];

    // 打劫父节点,则不可打劫子节点
    int val1=root->val;
    if(root->left) val1=val1+rob_2(root->left->left)+rob_2(root->left->right);
    if(root->right) val1=val1+rob_2(root->right->left)+rob_2(root->right->right);

    // 不打劫父节点,则可打劫子节点
    int val2=rob_2(root->left)+rob_2(root->right);
    val_map[root]= max(val1,val2);
    return val_map[root];
}

vector<int> Rob3::rob_Tree(TreeNode* root){
    if(!root) return {0,0}; // 下标0表示打劫,1表示不打劫
    vector<int> left= rob_Tree(root->left); // 打劫与不打劫左节点的最大值
    vector<int> right= rob_Tree(root->right); // 打劫与不打劫右节点的最大值

    int val1=root->val+left[1]+right[1]; // 打劫根节点,则不可打劫左右节点
    int val2=max(left[0],left[1])+max(right[0],right[1]); // 不打劫根节点,则可打劫左右节点
    // 但是也存在不打劫左节点时更大的值,故val2(不打劫根节点时表达式如上)
    return {val1,val2};
}

