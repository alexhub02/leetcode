#include "LinkList.h"

ListNode* CreatLinkList(int a[],int length)
{
    auto dummy = new ListNode();
    auto tail = dummy;
    for(int i = 0;i<length;i++){
        tail->next = new ListNode(*(a++));
        tail = tail->next;
    }
    auto p = dummy->next;
    delete dummy;
    return p;
}

void ShowLinkList(ListNode* &head)
{
    ListNode* p = head;
    while(p){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
}

ListNode* ReverseList(ListNode* head)
{
     ListNode* dummy = new ListNode(0,head);
     if(!head) return head;
     ListNode* p;
     while(head->next){
         p = head->next;
         head->next = p->next;
         p->next = dummy->next;
         dummy->next = p;
     }
     return dummy->next;
}

ListNode* ReverseList(ListNode* head,int left,int right)
{
    if(left==right) return head;
    ListNode* dummy = new ListNode(-1,head); // 用于返回整个链表
    ListNode* new_dummy = dummy; // 实际的防卫结点
    for(int i = 0;i<left-1;i++){
        head = head->next;
        new_dummy = new_dummy->next;
    }
    ListNode* p = head; // 临时变量用于存储当前结点的下一个结点
    for(int i = 0;i<right-left;i++){
        p = head->next;
        head->next = p->next;
        p->next = new_dummy->next;
        new_dummy->next = p;
    }
    return dummy->next;
}

ListNode* rotateRight(ListNode* head, int k) {
    if(!head||!head->next||k==0) return head;
    ListNode* tail = head;
    int nums = 1;
    while(tail->next){
        tail = tail->next;
        nums++;
    }
    tail->next = head;
    k = k%nums;
    for(int i =0;i<nums-k;i++){
        head = head->next;
        tail = tail->next;
    }
    tail->next = nullptr;
    return head;
}

bool hasCycle(ListNode *head) {
    if(!head||!head->next) return false;
    ListNode *fast = head->next;
    ListNode *slow = head;
    while(slow!=fast&&fast&&fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    if(slow==fast) return true;
    return false;
}
