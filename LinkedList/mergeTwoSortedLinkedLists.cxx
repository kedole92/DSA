Problem Description
Given 2 sorted linked lists, merge them into a new sorted linked list and return head of the merged list. The new list should be made by splicing (adjusting the pointers) together the nodes of the first two lists.

Input format
N - An integer denoting the number of nodes in the linked list.
N integers follow where ith integer denotes the ith node value in the linked list
M - An integer denoting the number of nodes in the linked list.
M integers follow where jth integer denotes the jth node value in the linked list

Output format
Return the sorted list after splicing the nodes of the first two lists.

Sample Input 1
3
1 2 4
3
1 3 4

Sample Output 1
1 1 2 3 4 4

Explanation 1
Merging the input lists and keeping the new list sorted results in this.

Sample Input 2
4
1 5 6 7
1
3

Sample Output 2
1 3 5 6 7

Explanation 2
Merging the input lists and keeping the new list sorted results in this.




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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // Handle base cases
        if (!l1) return l2;
        if (!l2) return l1;
        
        // Create a dummy head to simplify the merging process
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Merge while both lists have nodes
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        // Attach remaining nodes
        tail->next = (l1) ? l1 : l2;
        
        return dummy.next;
}
