int lenOfLinkedList(ListNode* head){
    int n = 0;
    while(head)
        n++,
        head = head->next;
    return n;
}