#ifndef BASIC_OPERATION_LINKLIST_H
#define BASIC_OPERATION_LINKLIST_H
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};


ListNode* CreatLinkList(int a[],int length); // 数组作为函数的参数进行传递时，数组就自动退化为同类型的指针
void ShowLinkList(ListNode* &head);
ListNode* ReverseList(ListNode* node); // 反转链表
ListNode* ReverseList(ListNode* node,int left,int right); // 反转特定位置区间的链表
ListNode* rotateRight(ListNode* head, int k); // 旋转链表
bool hasCycle(ListNode *head);
#endif //BASIC_OPERATION_LINKLIST_H
