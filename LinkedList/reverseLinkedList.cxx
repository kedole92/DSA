Problem Description
Given the elements of a linked list, reverse it.
You’ll have to implement the given method, which has the original list’s head pointer as an argument, and return the head of the updated list.

Input format
There are two lines of input.
First line contains N, the number of elements in the linked list.
Second line contains N space separated integers.

Output format
Only line contains N space separated integers

Sample Input 1
5
1 2 3 4 5

Sample Output 1
5 4 3 2 1

Explanation 1
1->2->3->4->5->NULL
5->4->3->2->1->NULL



class ListNode {
    public:
	int val;
	ListNode* next;

	ListNode() {}

	ListNode(int x) {                      
	    val = x;                       
	    next = NULL;
	}
};

ListNode* reverseLinkedList(ListNode *head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;

    while(curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;

}
