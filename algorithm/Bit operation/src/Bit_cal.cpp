#include "Bit_cal.h"

void basic_operation(){
    int a = 10;
    int b = 3;
    // 输出的是补码,用于运算的也是补码
    cout<<"a:\t"<<bitset<8>(a)<<endl; // 转换为2进制数后输出8位
    cout<<"b:\t"<<bitset<8>(b)<<endl; // 转换为2进制数后输出8位
    cout<<"a&b:\t"<<bitset<8>(a&b)<<endl; // 与运算
    cout<<"a|b:\t"<<bitset<8>(a|b)<<endl; // 或运算
    cout<<"a^b:\t"<<bitset<8>(a^b)<<endl; // 异或运算
    cout<<"~a:\t"<<bitset<8>(~a)<<endl; // 取反运算
    cout<<"a<<3:\t"<<bitset<8>(a<<3)<<endl; // 左移
    cout<<"a>>1:\t"<<bitset<8>(a>>1)<<endl; // 右移
}

void show_complement(){
    int a = -1;
    cout<<"a:\t"<<bitset<8>(a)<<endl;
    int b = 1;
    cout<<"b:\t"<<bitset<8>(b)<<endl;
    int c = 127;
    cout<<"c:\t"<<bitset<8>(c)<<endl;
}

void cal(){
    // 原码就是符号位+绝对值的二进制表示
    // 正数的反码是其本身,负数的反码是原码的基础上符号位不变,其余位取反
    // 正数的补码是其本身,负数的补码是原码基础上符号位不变,其余为取反然后+1(反码基础上+1)
    // 负数的补码高位用1补齐,正数的用0补齐
    int a = 0;
    cout<<"a:\t"<<bitset<8>(a)<<endl;
    int b = 39;
    cout<<"b:\t"<<bitset<8>(b)<<endl;
    cout<<"a^b:\t"<<bitset<8>(a^b)<<endl;
    cout<<"a^b^b:\t"<<bitset<8>(a^b^b)<<endl;
}

