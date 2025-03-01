// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* mergedList = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* head = mergedList;


    while (list1 && list2){
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));


        if (list1->val > list2->val ){
            
            newNode->val = list2->val;
            mergedList->next = newNode;
            list2=list2->next;
            mergedList = mergedList->next;

        } else{
            newNode->val = list1->val;
            mergedList->next = newNode;
            list1 = list1->next;
            mergedList = mergedList->next;
        }
    }

    if (!list1) {
        mergedList->next = list2;
    }
    if (!list2) {
        mergedList->next = list1;
        }
    return head->next;
}