Problem Description
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.

Input format
First line contains an integer n - Number of nodes.
Second line contains n space separated integers - The value of nodes.
Next n lines contain 3 space separated integers i, l, r describing left and right child of ith node as l and r respectively.

Output format
Print an integer - The length of the diameter.

Sample Input 1
8
10 15 25 12 40 16 8 9
1 5 3
5 6 -1
6 -1 7
7 -1 -1
3 2 4
2 8 -1
8 -1 -1
4 -1 -1

Sample Output 1
6

Explanation
The binary tree is:-
The path 8->16->40->10->25->15->9 has 6 edges in it and is the longest path in the given tree.


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
}


int maxDiameter = 0;
static int findHeight(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        
        int leftHeight = findHeight(node->left);
        int rightHeight = findHeight(node->right);
        
        // Update diameter if current path is longer
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);
        
        // Return height of current subtree
        return max(leftHeight, rightHeight) + 1;
    }

int diameterOfBinaryTree(TreeNode* root) {
    if (root == NULL) {
            return 0;
        }
        
    findHeight(root);
    return maxDiameter;
}
