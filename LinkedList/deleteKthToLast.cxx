Problem Description
Given a linked list, remove the Kth node from the end of the list and return its head.
Note: the given K will always be a valid node.

Input format
There are three lines of input
First line contains N, the number of nodes in the linked list
Second line contains N integers, denoting the values of the linked list
Third line contains K, the node to be deleted from the end.

Output format
Return the head of the LL after deleting the Kth node from the end.

Function definition
You have to complete the given function. It accepts two arguments - the head of the linked list, and k. You have to return the head of the LL after making the necessary change.

Constraints
1 <= N<= 10^5
-10^9 <= value <= 10^9
1 <= K <= N

Sample Input 1
5
1 5 2 4 3
2

Sample Output 1
1 5 2 3

Explanation 1
The 2nd node from the end is 4, removing which, gives us 1 5 2 3

Sample Input 2
5
3 1 3 2 4
4

Sample Output 2
3 3 2 4

Explanation 2
The 4th node from the end is 1, removing which, gives us 3 3 2 4




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

ListNode* deleteKthToLast(ListNode* head , int k) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* fast = dummy;
    ListNode* slow = dummy;

    for(int i=0; i<k; ++i)
    {
        if(fast->next != nullptr)
        {
            fast = fast->next;
        }
    }

    while(fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode* toDelete = slow->next;
    slow->next = toDelete->next;
    delete toDelete;

    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;

}
