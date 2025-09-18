Problem Description
Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

Input format
First line contains an integer T - Number of test cases.
For each test case:-
First line contains an integer n - Number of nodes.
Second line contains n space separated integers - The value of nodes.
Next n lines contain 3 space separated integers i, l, r describing left and right child of ith node as l and r respectively.

Output format
Output the balanced tree in the same format as given in input.

Note: You just have to return the balanced tree’s root, the input/output is handled.

Sample Input 1
1
4
40 20 10 30
1 2 -1
2 3 4
3 -1 -1
4 -1 -1

Sample Output 1
1
4
20 10 30 40
1 2 3
2 -1 -1
3 -1 4

4 -1 -1



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

// Helper function to store inorder traversal
static void inorderTraversal(TreeNode* root, vector<long>& nodes) {
        if (root == NULL) return;
        
        inorderTraversal(root->left, nodes);
        nodes.push_back(root->val);
        inorderTraversal(root->right, nodes);
    }
    
    // Helper function to create balanced BST from sorted array
static TreeNode* sortedArrayToBST(vector<long>& nums, int start, int end) {
        if (start > end) return NULL;
        
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = sortedArrayToBST(nums, start, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, end);
        
        return root;
    }

TreeNode* balanceBST(TreeNode* root) {
    vector<long> nodes;
    inorderTraversal(root, nodes);
        
    // Step 2: Create balanced BST from sorted array
    return sortedArrayToBST(nodes, 0, nodes.size() - 1);
}
