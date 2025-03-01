// 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


 struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode* total_sum = (struct ListNode*)malloc(sizeof(struct ListNode));

    //i defined total sum as an linkedlist struct as well, and give it the size of an int

    struct ListNode* head = total_sum;
    //saves head of linkedlist (for return)


    //cloned total_sum ListNode to 'current' var


    int carry = 0;
    while (l1 || l2 || carry){
        int val1 = (l1) ? l1->val : 0; // defined val1 as l1->val if it is !=null, and 0 if it is null
        int val2 = (l2) ? l2->val : 0; 

        l1 = (l1) ? l1->next : NULL;
        l2 = (l2) ? l2->next : NULL;
        
        int sum = val1 + val2 + carry;
        carry = sum/10; 
        sum %= 10; 


        total_sum->val = sum;

        if (l1|| l2 || carry){
            total_sum->next =  (struct ListNode*)malloc(sizeof(struct ListNode));
            total_sum = total_sum->next;   
        } else {
            total_sum->next = NULL;
        }
             
    }


    return head;
}