#include<iostream>


using namespace std;

struct ListNode
{
    int data;
    ListNode* next;

    ListNode(int val)
    {
        data = val;
        next = NULL;
    }
};

ListNode* middleNode(ListNode* head) 
{
 ListNode* slow = head;
 ListNode* fast = head;

 while (fast != NULL && fast->next != NULL)
 {
     slow = slow->next;
     fast = fast->next->next;
 }
 return slow;
}