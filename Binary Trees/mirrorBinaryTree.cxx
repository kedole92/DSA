Solve below problem:

https://www.crio.do/learn/PSDS/ME_DSA_TREE_RECURSION/ME_DSA_TREE_RECURSION_MODULE_MIRRORBINARYTREE/


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

TreeNode* mirrorBinaryTree(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    
    // Recursively mirror left and right subtrees
    TreeNode* leftSubtree = mirrorBinaryTree(root->left);
    TreeNode* rightSubtree = mirrorBinaryTree(root->right);
    
    // Swap the subtrees
    root->left = rightSubtree;
    root->right = leftSubtree;
    
    return root;
}
