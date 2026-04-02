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

ListNode *RemoveCycle(ListNode *head) {
        if (head == NULL) {
            return NULL; 
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                
                ListNode *fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;  
            }
        }
        return NULL;
    }