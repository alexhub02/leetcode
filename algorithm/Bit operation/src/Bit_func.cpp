#include "Bit_cal.h"

bool isPowerOfTwo(int n){
    /*
 * n-1表明n二进制表示下单最低的1位起往下均取反,高位不变
 * n与n-1相与,若为0则表明n二进制表示仅有1位不为0,n是2的幂次方
*/
    return n>0&&(n&(n-1))==0;
}

int hammingWeight(uint32_t n) {
    /*
 * 逐步将1左移0-31步与n相进行&运算,为1表示n该位不为0
*/
    int ans = 0;
    for(int i =0;i<32;i++){
        if((1<<i)&n) ans++;
    }
    return ans;
}

int singleNumber(vector<int>& nums) {
    vector<int> bit_array(32,0);
    int len = nums.size();
    for(int i = 0;i<len;i++){
        for(int j =0;j<32;j++){
            if((1<<j)&nums[i]) bit_array[j]++;
        }
    }
    int ans = 0;
    for(int i =0;i<32;i++){
        if(bit_array[i]%3) ans+= 1<<i;
    }
    return ans;
}

int once_num_1(vector<int> & nums){
    /*
 * a^b^b=a; 0^0=0; 0^1=1;-> 0与n进行异或运算为n
 * 将0与数组中每个元素逐个进行^运算,最终所得即为
*/
    int ans = 0;
    int len = nums.size();
    for(int i = 0;i<len;i++){
        ans ^= nums[i];
    }
    return ans;
}

int once_num_2(vector<int> & nums){
    /*
 * 也可以将num中的元素求和再减去1-10的和,但是当1-10这个序列变为大序列时容易溢出
*/
    int ans = 0;
    int len = nums.size();
    for(int i = 0;i<len;i++){
        ans ^= nums[i];
    }
    for(int i = 1;i<=10;i++){
        ans ^= i;
    }
    return ans;
}

vector<int> once_num_3(vector<int> & nums){
    /*
 * 先进行第一次遍历算得num1^num2,记作num,num必不为0,找出num最低不为0的位N
 * N与nums中元素异或,通过是否为0可以区分出num1与num2
*/
    int len = nums.size();
    vector<int> ans;
    if(len<2) return ans;
    int num = 0; // num1^num2
    for(int i = 0;i<len;i++){
        num ^= nums[i];
    }
    // 找到num1中最低的非0位,第N位,该位是num1与num2从低位开始第一个不同的位,故可区分num1与num2
    int N = 1;
    int num1 = 0,num2 = 0;
    while(!(N&num)) N<<=1;
    for(int i = 0;i<len;i++){
        if(nums[i]&(N))num1 ^= nums[i];
        else num2 ^= nums[i];
    }
    ans = {num1,num2};
    return ans;
}

