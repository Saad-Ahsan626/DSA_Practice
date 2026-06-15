#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}

};

ListNode* deleteMiddle(ListNode* head) 
{
    if (!head || !head->next) 
    {
        return nullptr;
    }
    
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) 
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    prev->next = slow->next;
    delete slow;
    return head;
}

