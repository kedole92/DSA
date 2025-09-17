Solve below problem:

https://www.crio.do/learn/PSDS/ME_DSA_TREE_RECURSION/ME_DSA_TREE_RECURSION_MODULE_BINARYTREEBOUNDARYTRAVERSAL/

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

Use new TreeNode(data) to create new Node
*/
// Check if node is leaf
    static bool isLeaf(TreeNode* node) {
        return (node->left == NULL && node->right == NULL);
    }
    
    // Add left boundary nodes (excluding leaves)
    static void addLeftBoundary(TreeNode* root, vector<int>& res) {
        TreeNode* curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) {
                res.push_back(curr->val);
            }
            if (curr->left) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }
    
    // Add leaf nodes
    static void addLeaves(TreeNode* root, vector<int>& res) {
        if (isLeaf(root)) {
            res.push_back(root->val);
            return;
        }
        if (root->left) addLeaves(root->left, res);
        if (root->right) addLeaves(root->right, res);
    }
    
    // Add right boundary nodes (excluding leaves) in reverse order
    static void addRightBoundary(TreeNode* root, vector<int>& res) {
        TreeNode* curr = root->right;
        vector<int> tmp;
        while (curr) {
            if (!isLeaf(curr)) {
                tmp.push_back(curr->val);
            }
            if (curr->right) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        // Add right boundary nodes in reverse order
        for (int i = tmp.size()-1; i >= 0; --i) {
            res.push_back(tmp[i]);
        }
    }

vector<int> binaryTreeBoundaryTraversal(TreeNode* root) {
    vector<int> res;
        if (root == NULL) return res;
        
        // Add root if it's not a leaf
        if (!isLeaf(root)) {
            res.push_back(root->val);
        }
        
        // Add left boundary
        addLeftBoundary(root, res);
        
        // Add leaf nodes
        addLeaves(root, res);
        
        // Add right boundary in reverse order
        addRightBoundary(root, res);
        
        return res;
}
