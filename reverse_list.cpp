struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(NULL) {}
	ListNode(int v) :val(v), next(NULL) {}
};
ListNode* reverseList(ListNode* head, int count) {
	if (count == 0)return head;
	ListNode* guardNode = new ListNode();
	ListNode* node = head;
	while (node && (count>0 || count == -1)) {
		ListNode* next = node->next;
		node->next = guardNode->next;
		guardNode->next = node;
		node = next;
		if (count != -1)
			count--;
	}
	head->next = node;
	return guardNode->next;
}
