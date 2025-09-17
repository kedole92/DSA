Problem Description
Given preorder and inorder traversal of a tree, construct the binary tree.
Note: You may assume that duplicates do not exist in the tree.

Input format
First line contains N, the number of elements in the tree.
Next line contains N space separated integers, denoting preorder.
Next line contains N space separated integers, denoting inorder.

Output format
Print two lines by traversing the constructed binary tree.
First line should contain N space separated integers, denoting preorder.
Second line should contain N space separated integers, denoting inorder.

Sample Input 1
6
1 2 4 5 3 6
5 4 2 1 3 6

Sample Output 1
1 2 4 5 3 6
5 4 2 1 3 6

Explanation 1
The output writes out the preorder and inorder sequence by traversing the binary tree constructed, so it should be the same as the output.


class TreeNode {
public:
    long val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {}

    TreeNode (long x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};
*/
static TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, 
                         int& preIndex, int inStart, int inEnd,
                         unordered_map<int, int>& inMap) {
    if (inStart > inEnd) {
        return NULL;
    }
    
    // Create root node from current preorder element
    TreeNode* root = new TreeNode(preorder[preIndex++]);
    
    // Find position of root in inorder
    int inIndex = inMap[root->val];
    
    // Recursively construct left and right subtrees
    root->left = buildTree(preorder, inorder, preIndex, inStart, inIndex - 1, inMap);
    root->right = buildTree(preorder, inorder, preIndex, inIndex + 1, inEnd, inMap);
    
    return root;
}

TreeNode* constructBinaryTreeFromPreorderAndInorderTraversal(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty() || inorder.empty()) {
        return NULL;
    }
    
    // Create hash map for inorder traversal
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    
    int preIndex = 0;
    return buildTree(preorder, inorder, preIndex, 0, inorder.size() - 1, inMap);
}
