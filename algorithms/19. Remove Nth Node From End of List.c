// 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



 
 struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* prev = (struct ListNode*)malloc(sizeof(struct ListNode));

    for (int i= 0; i < n ; i++){
            if (fast == NULL) return head;

            fast = fast->next;
        
        }

    if (!fast){
        prev = head;
        head = head->next;
        free(prev);
        return head;
    }

    
    while (fast){
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }
    
    prev->next = slow->next;
    free(slow);

    
    return head;


    
}
