/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int SIZE = 100003;
    struct ListNode **set = calloc(SIZE, sizeof(struct ListNode*)); 

    while (headA != NULL) {
        int i = (unsigned long)headA % SIZE;  
        while (set[i] != NULL) i = (i + 1) % SIZE; 
        set[i] = headA;
        headA = headA->next;
    }

    while (headB != NULL) {
        int i = (unsigned long)headB % SIZE;
        while (set[i] != NULL) {
            if (set[i] == headB) return headB; 
            i = (i + 1) % SIZE;
        }
        headB = headB->next;
    }

    return NULL; 
}
