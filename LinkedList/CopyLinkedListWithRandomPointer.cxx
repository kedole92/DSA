
Problem Description
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list i.e. the head of the copied linked list.
The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.
For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
The original list should be restored if modified.

Input format:
Next line contains X space separated integers, elements of the linked list.
Next line contains X space separated integers, random pointers of each node in the linked list.

Output format
Return a deep copy of the list i.e. the head of the copied linked list.

Sample Input 1
10 20
2 2

Sample Output 1
10 20
20 20

Explanation 1
========================

View of the Linked list

========================
{10.next} -> {20}
and
{20.next} -> {null}
{10.random} -> {20}
and
{20.random} -> {20}



class Node {
    public:
	int val;
    Node* next;
    Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
    Node(int x) {
        val = x;
        next = random = NULL;
    }
};
class CopyLinkedListWithRandomPointer {
public:
	Node* copyLinkedListWithRandomPointer(Node* head) {
        if (head == NULL) return NULL;
        
        // Step 1: Create copy nodes and insert them between original nodes
        Node* curr = head;
        while (curr != NULL) {
            // Create new node with all three required arguments
            Node* copy = new Node(curr->val, NULL, NULL);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }
        
        // Step 2: Assign random pointers for the copy nodes
        curr = head;
        while (curr != NULL) {
            if (curr->random != NULL) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        // Step 3: Separate the original and copied lists
        Node* original = head;
        Node* copy = head->next;
        Node* copyHead = head->next;
        
        while (original != NULL && copy != NULL) {
            original->next = original->next ? original->next->next : NULL;
            copy->next = copy->next ? copy->next->next : NULL;
            original = original->next;
            copy = copy->next;
        }
        
        return copyHead;
    }
};
