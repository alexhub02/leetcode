#ifndef BIT_OPERATION_BIT_CAL_H
#define BIT_OPERATION_BIT_CAL_H
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
void basic_operation();
void show_complement(); // 补码可视化

void cal(); // 位运算测试

bool isPowerOfTwo(int n); // lc_231,2的幂次方
int hammingWeight(uint32_t n); // lc_191,位1的个数
int singleNumber(vector<int>& nums); //lc_137,只出现1次的数字2
/*
 * 题型1:
 * 给出数组nums,其中有且仅有一个数出现了奇数次
 * 其余的数都出现了偶数次,用线性时间复杂度、常数空间复杂度找出出现了奇数次的那个数
 * 题型2:
 * 给出11个整数,由1-10以及1-10中一个任意元素组成,求出出现两次的元素
 * 题型3:
 * 给出数组nums,其中有且仅有2个数出现了1次
 * 其余的数都出现了偶数次,用线性时间复杂度、常数空间复杂度找出出现了1次的两个数
*/
int once_num_1(vector<int> & nums);
int once_num_2(vector<int> & nums);
vector<int> once_num_3(vector<int> & nums);
#endif //BIT_OPERATION_BIT_CAL_H
