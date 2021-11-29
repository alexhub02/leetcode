#include "test_func.h"

void ReverseList_test(){
    // 反转位置2-4之间的链表
    ListNode *head = new ListNode();
    int arr[] = {1,2,3,4,5};
    int length = sizeof(arr) / sizeof(arr[0]);
    head = CreatLinkList(arr, length);
    cout<<"Original LinkList:";
    ShowLinkList(head);
    ListNode *new_head = ReverseList(head,2,4);
    cout<<"After reverse:";
    ShowLinkList(new_head);
}

void rotateRight_test(){
    // 旋转链表,右旋2个单位
    ListNode *head = new ListNode();
    int arr[] = {1,2,3,4,5};
    int length = sizeof(arr) / sizeof(arr[0]);
    head = CreatLinkList(arr, length);
    cout<<"Original LinkList:";
    ShowLinkList(head);
    head = rotateRight(head,2);
    cout<<"After rotate:";
    ShowLinkList(head);
}

void hasCycle_test(){
    // 测试环
    ListNode *head = new ListNode();
    int arr[] = {1,2,3,4,5};
    int length = sizeof(arr) / sizeof(arr[0]);
    head = CreatLinkList(arr, length);
    cout<<"Original LinkList:";
    ShowLinkList(head);
    if(!head) cout<<"LinkList is empty"<<endl;
    ListNode* tail = head;
    while(tail->next)
        tail = tail->next;
//    tail->next = head->next->next; // 添加环
    cout<<hasCycle(head)<<endl;
}