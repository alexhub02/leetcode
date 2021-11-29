#include "Partition.h"

bool Partition::is_Palindrome(string& s){
    if(s.size()==0) return false;
    int left = 0;
    int right = s.size()-1;
    while(left<=right){
        if(s[left]!=s[right]) return false;
        left++;
        right--;
    }
    return true;
}

void Partition::backtracking(string &s,int start_index,int len){
    if(start_index>=len){
        ans.push_back(path);
        return;
    }
    int step = 1;
    for(int i = start_index;i+step<=len;step++){
        string sub_string = s.substr(start_index,step);
        if(!is_Palindrome(sub_string)) continue;
        path.push_back(sub_string);
        backtracking(s,start_index+step,len);
        path.pop_back();
    }
}

void RestoreIpAddresses::backtracking(string &s,int start_index,int len){
    if(path.size()==4&&start_index>=len){
        string sub_s;
        for(int i=0;i<4;i++){
            sub_s += path[i];
            if(i<3) sub_s += '.';
        }
        ans.push_back(sub_s);
        return;
    }
    if((start_index+(4-path.size())*3<len)||(path.size()<4&&start_index>=len)){
        // 无法添加完字符串时剪枝,没有凑满4个整数时剪枝
        return;
    }
    for(int i=1;i<=3;i++){
        if(start_index+i>len) return;
        string sub_s = s.substr(start_index,i);
        if((i>1&&sub_s[0]=='0')||(atoi(sub_s.c_str())>255)) continue;
        path.push_back(sub_s);
        backtracking(s,start_index+i,len);
        path.pop_back();
    }

}