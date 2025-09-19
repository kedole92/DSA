Problem Description
Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a binary search tree. You may assume that each parent has a link to its child.

Input format
The tree will be given along with the node for which you have to find the successor.

Q: Q number of queries will be given to you.

Output format
Print the value of the successor node. If it doesn’t exist then print -1.

Sample Input 1
3
5 4 6
0 1 2
1 -1 -1
2 -1 -1
2
2
0

Sample Output 1
-1
6
There will be no successor of node with value 6.

class TreeNode {
public:
    long val;
    TreeNode* left;
    TreeNode* right;
    TreeNode (long x) {
        val = x;
        left = NULL;
        right = NULL;
    }

class Solution {
    public:
        TreeNode * inOrderSuccessor(TreeNode *root, TreeNode *givenNode) 
        {
             TreeNode* successor = NULL;
          
            // Start from root and search for the given node
            while (root != NULL) {
                // If current node's value is greater than given node's value,
                // this could be the successor. Store it and go left
                if (root->val > givenNode->val) {
                    successor = root;
                    root = root->left;
                }
                // If current node's value is less than or equal to given node's value,
                // successor must be in right subtree
                else {
                    root = root->right;
                }
            }
            return successor;
        } 
};

The successor of node having value 5 will be the node with value 6.
