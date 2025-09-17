Solve below problem:

https://www.crio.do/learn/PSDS/ME_DSA_TREE_RECURSION/ME_DSA_TREE_RECURSION_MODULE_TOPVIEWBINARYTREE/



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

vector<int> topViewBinaryTree(TreeNode* root) {
     vector<int> ans;
    if (root == NULL) {
        return ans;
    }
    
    // Map to store horizontal distance -> node value
    map<int, int> topNodes;
    
    // Queue to store node and its horizontal distance
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    
    // Level order traversal
    while (!q.empty()) {
        TreeNode* current = q.front().first;
        int hd = q.front().second;  // horizontal distance
        q.pop();
        
        // If this is the first node at this horizontal distance,
        // add it to the map
        if (topNodes.find(hd) == topNodes.end()) {
            topNodes[hd] = current->val;
        }
        
        // Add left child with horizontal distance - 1
        if (current->left) {
            q.push({current->left, hd - 1});
        }
        
        // Add right child with horizontal distance + 1
        if (current->right) {
            q.push({current->right, hd + 1});
        }
    }
    
    // Extract values from map to vector
    for (auto it : topNodes) {
        ans.push_back(it.second);
    }
    
    return ans;
}
