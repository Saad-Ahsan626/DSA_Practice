#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int value)
    {
        val = value;
        next = NULL;
    }
};

ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL) 
    {
        return NULL; 
    }

    ListNode* current = head;

    while (current != NULL && current->next != NULL)
     {
        if (current->val == current->next->val) 
        {
            ListNode* temp = current->next;
            current->next = current->next->next; 
            delete temp; 
        } 
        else 
        {
            current = current->next; 
        }
    }

    return head;
    
}