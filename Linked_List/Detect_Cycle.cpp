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

bool hasCycle(ListNode *head) {
    if (head == NULL) {
        return false; 
    }

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        if (slow == fast) {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return false;
}