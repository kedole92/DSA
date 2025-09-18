Problem Description
Given a binary search tree, write a function to find the node with the kth smallest value in it and return its value.

Note: You may assume that k is always valid, 1 ≤ k ≤ BST's total elements.

Input format
Line1 to X: Details of the binary tree structure (refer section below for the format)

Last line contains a single integer k.

Output format
Print the value of the kth smallest element.

Constraints
1 <= Number of nodes (N) <= 105

1 <= Value of nodes <= 109

1 <= k <= N

Sample Input 1
4

3 1 4 2

1 2 3

2 -1 4

3 -1 -1

4 -1 -1

1

Sample Output 1
1

Explanation 1
image

1 is the 1st smallest element in this BST




class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode (long x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};
*/

int count;  // Keep track of nodes visited
int result; // Store the kth smallest value
    
static void inorderTraversal(TreeNode* root, int k, int& visited, int& answer) {
        if (root == NULL || visited >= k) return;
        
        // Traverse left subtree
        inorderTraversal(root->left, k, visited, answer);
        
        // Process current node
        visited++;
        if (visited == k) {
            answer = root->val;
            return;
        }
        
        // Traverse right subtree
        inorderTraversal(root->right, k, visited, answer);
};

int kthSmallestElementInABst(TreeNode* root, int k) {
    int visited = 0;
        int answer = 0;
        inorderTraversal(root, k, visited, answer);
        return answer;
};
