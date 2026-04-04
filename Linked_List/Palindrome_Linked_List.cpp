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

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* prev = NULL;
    ListNode* curr = slow;

    while (curr) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }

    ListNode* left = head;
    ListNode* right = prev;

    while (right) {
        if (left->val != right->val) return false;
        left = left->next;
        right = right->next;
    }
    return true;

}
