ListNode* reverseLinkedList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}