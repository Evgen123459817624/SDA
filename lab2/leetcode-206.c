/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    struct ListNode* end = NULL;

    while (end != head) {
        struct ListNode* p = head;
        while (p->next != end) p = p->next;

        tail->next = malloc(sizeof(struct ListNode));
        tail = tail->next;
        tail->val = p->val;

        end = p;
    }
    tail->next = NULL;

    return dummy.next;
}