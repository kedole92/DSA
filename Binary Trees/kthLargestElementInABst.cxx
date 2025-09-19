Problem Description
Given a Binary Search Tree (BST) and a positive integer k, find the k’th largest element in the Binary Search Tree.

Input format
First line contains an integer n - Number of nodes.
Second line contains n space separated integers - The value of nodes.
Next n lines contain 3 space separated integers i, l, r describing left and right child of ith node as l and r respectively.
Last line contains an integer k - The kth largest element to be searched

Output format
Print the value of the kth largest element.

Sample Input 1
7
40 20 60 10 30 50 70
1 2 3
2 4 5
3 6 7
4 -1 -1
5 -1 -1
6 -1 -1
7 -1 -1
3

Sample Output 1
50


class TreeNode {
public:
    long val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    TreeNode (long x) {
        val = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
}

Use new TreeNode(data) to create new Node
*/

static int helper(TreeNode* root, int k, int& counter)
{
    if(!root)
        return -1;

    int val = helper(root->right, k, counter);
    if(val != -1)
        return val;
    
    counter++;

    if(counter==k)
        return root->val;

    return helper(root->left, k, counter);

}

int kthLargestElementInABst(TreeNode *root, int k) {
    int counter = 0;

    return helper(root, k, counter);
}
