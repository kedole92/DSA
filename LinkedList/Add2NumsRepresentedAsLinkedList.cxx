You’re given two numbers represented by two linked lists, where each node contains a single digit. The digits are stored in forward order i.e the one’s digit is at the tail of the list. Write a function that adds the two numbers and returns the sum as a linked list in the same order.

Input format
There are 4 lines of input.
First line contains N, the size of the first list
Next line contains N space separated integers
Third line contains M, the size of the second list
Next line contains M space separated integers

Output format
Return the resultant list after adding given lists.

Function definition
The given function accepts two arguments - representing the heads of the two lists,and returns the new head.

Constraints
1 <= N <= 1e5
1 <= M <= 1e5
0 <= value <= 9

Sample Input 1
3
6 1 7
3
2 9 5

Sample Output 1
9 1 2

Explanation 1
617 + 295 = 912.

Sample Input 2
2
4 9
1
5

Sample Output 2
5 4

Explanation 2
49 + 5 = 54.



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

ListNode *reverse(ListNode *head) {
    ListNode *prev = nullptr, *curr = head, *next;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to trim leading zeros in linked list
ListNode *trimLeadingZeros(ListNode* head) {
	while(head->next != nullptr && head->val == 0)
    	head = head->next;
	return head;
}

// function to find the length of linked list
int countNodes(ListNode* head) {
	int len = 0;
  	ListNode* curr = head;
  
  	while(curr != nullptr) {
    	len += 1;
      	curr = curr->next;
    }
  	return len;
}

ListNode* sumLists2(ListNode* head1 , ListNode* head2) {
   head1 = trimLeadingZeros(head1);
	head2 = trimLeadingZeros(head2);
  
  	// Find the length of both the linked lists
  	int len1 = countNodes(head1);
  	int len2 = countNodes(head2);
  	
  	// If head1 is smaller, swap the two linked lists by
  	// calling the function with reversed parameters
	if(len1 < len2)
      	return sumLists2(head2, head1);

    int carry = 0;
    head1 = reverse(head1);
    head2 = reverse(head2);
  
	ListNode *res = head1;
  
    // Iterate till either head2 is not empty or
  	// carry is greater than 0
    while (head2 != nullptr || carry != 0) {
      
      	// Add carry to head1
        head1->val += carry;

        // If head2 linked list is not empty, add it to head1
        if (head2 != nullptr) {
            head1->val += head2->val;
            head2 = head2->next;
        }
      
        // Store the carry for the next nodes
        carry = head1->val / 10;
      	
      	// Store the remainder in head1
      	head1->val = head1->val % 10;
      	
      	// If we are at the last node of head1 but carry is 
      	// still left, then append a new node to head1
      	if(head1->next == nullptr && carry != 0)
        	head1->next = new ListNode(0);
      
      	head1 = head1->next;
    }

    // Reverse the resultant linked list to get the
    // required linked list
    return reverse(res);
}
