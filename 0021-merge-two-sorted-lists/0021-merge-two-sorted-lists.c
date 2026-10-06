/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head;

    if (list1 == NULL)
        return list2;

    if (list2 == NULL)
        return list1;

    if (list1->val < list2->val) {
        head = list1;
        head->next = mergeTwoLists(list1->next, list2);
    } else {
        head = list2;
        head->next = mergeTwoLists(list1, list2->next);
    }

    return head;
}