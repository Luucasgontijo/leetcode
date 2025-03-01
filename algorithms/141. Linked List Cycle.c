// 141. Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    if (head == NULL || head->next == NULL){
        return false; 
    }
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow){
            return true;
        }
    }
    return false;

}