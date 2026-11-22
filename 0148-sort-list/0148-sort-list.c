
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    // Find middle of the list
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the list into two halves
    prev->next = NULL;

    // Sort both halves
    struct ListNode *left = sortList(head);
    struct ListNode *right = sortList(slow);

    // Merge two sorted lists
    struct ListNode dummy;
    struct ListNode *tail = &dummy;

    while (left != NULL && right != NULL) {
        if (left->val < right->val) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }

        tail = tail->next;
    }

    if (left != NULL)
        tail->next = left;
    else
        tail->next = right;

    return dummy.next;
}
