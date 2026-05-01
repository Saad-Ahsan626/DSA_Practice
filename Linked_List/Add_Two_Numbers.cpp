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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{

    ListNode* head = NULL;
    ListNode* tail = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) 
    {
        int sum = carry;

        if (l1 != NULL) 
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) 
        {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        ListNode* newNode = new ListNode(sum % 10);

        if (head == NULL) 
        {
            head = newNode;
            tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return head;
}