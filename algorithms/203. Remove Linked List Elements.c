// 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* temp = head;
    struct ListNode* prev = head;
    while (temp){
        

        if (temp->val == val){
            if (temp->val == head->val ){
                head = head->next;
            }
            prev->next = temp->next;
            temp = temp->next;
        } else{
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}