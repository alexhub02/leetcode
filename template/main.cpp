#include <iostream>
using namespace std;
#include<unordered_map>
#include<unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> ans(len,0);
        stack<int> s;
        for(int i=0;i<len;i++){
            while(!s.empty()&&temperatures[i]>temperatures[s.top()])
            {
                ans[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};

int main() {
    vector<int> nums {4,10,4,3,8,9};
    Solution s;
    return 0;
}
