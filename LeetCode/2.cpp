
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
	ListNode *node = new ListNode(0);
	ListNode *head = node;
	int carry = 0;

	while(l1 || l2){
		if(l1){
			carry += l1->val;
			l1 = l1->next;
		}
		if(l2){
			carry += l2->val;
			l2 = l2->next;
		}

		node->val = carry%10;
		carry /= 10;
		if(l1 || l2 || carry){
			node->next = new ListNode(carry);
			node = node->next;
		}
	}

	return head;
}