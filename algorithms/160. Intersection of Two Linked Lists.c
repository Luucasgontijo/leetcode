// 160. Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* tempA = headA;
    struct ListNode* tempB = headB;
    int A_length = 0, B_length = 0;

    if (!headA || !headB){
        return NULL;
    }


    while (tempA){
        tempA = tempA->next;
        A_length++;
    }
    

    while (tempB){
        tempB = tempB->next;
        B_length++;
    }
    
    tempA = headA;
    tempB = headB;




    if (A_length > B_length ){
        for (int i = 0; i < A_length - B_length; i++){
            tempA = tempA->next;
        }
    } else {
            for (int i = 0; i < B_length - A_length; i++){
            tempB = tempB->next;
        }
    }

    while (tempA != tempB){
        tempA = tempA->next;
        tempB = tempB->next;
    }

    return tempA;
    


}
