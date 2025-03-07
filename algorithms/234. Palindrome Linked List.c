// 234. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/description/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 struct ListNode* reverseLinkedList(struct ListNode* head){
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* nextNode = NULL;

    while(curr){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    // struct ListNode* temp = (ListNode*)malloc(sizeof(ListNode));


     while (fast && fast->next){
        slow = slow->next;
        fast= fast->next->next;
    }



    struct ListNode* rightHead = reverseLinkedList(slow);
    while (rightHead){
        if (head->val !=rightHead-> val){
            return false;
        }
        head = head->next;
        rightHead = rightHead->next;
    }
    return true;
}