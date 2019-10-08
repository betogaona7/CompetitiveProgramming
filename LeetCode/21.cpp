ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *node = new ListNode(0);
    ListNode *head = node;
    while(l1 && l2){
        if(l1->val < l2->val){
            node->next = new ListNode(l1->val);
            node = node->next;
            l1 = l1->next;
        }else if (l1->val == l2->val){
            node->next = new ListNode(l1->val);
            node = node->next;
            node->next = new ListNode(l2->val);
            node = node->next;
            l1 = l1->next;
            l2 = l2->next;
        }else{
            node->next = new ListNode(l2->val);
            node = node->next;
            l2 = l2->next;
        }
    }
    if(l1) node->next = l1;
    if(l2) node->next = l2;
    return head->next;        
}