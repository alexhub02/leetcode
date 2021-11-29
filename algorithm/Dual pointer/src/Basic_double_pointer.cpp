#include "Basic_double_pointer.h"

string Solution_151::reverseWords(string s) {
    int len=s.size();
    int l=s.size()-1;
    string ans("");
    while(l>=0){
        if(s[l]!=' '){
            int r=l;
            while(l>=1&&s[l-1]!=' ') l--;
            if(l==1&&s[l-1]!=' ') l=0; // 如果停在索引1,则检查下一个是否为空格
            if(ans.size()) ans=ans+" "+s.substr(l,r-l+1);
            else ans=ans+s.substr(l,r-l+1);
        }
        l--; // 不管是否进行操作,均移动左指针,避免边界0处存在连续字符后l=0陷入死循环
    }
    return ans;
}