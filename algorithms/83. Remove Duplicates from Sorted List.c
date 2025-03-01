// 83. Remove Duplicates from Sorted List
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp){
        if (!temp->next){
            return head;
        }
         if (temp->val == temp->next->val){
            temp->next = temp->next->next;
        } else{
            temp = temp->next;
        }
        
        
    }
    return head;
}