You are given a binary tree.
You need to find the nodes in order of top to bottom which will be visible when the tree is viewed from the right side.

The visible nodes from top to bottom are 1, 3 and 4.

Input format
First line contains an integer n - Number of nodes.
Second line contains n space separated integers - The value of nodes.
Next n lines contain 3 space separated integers i, l, r describing left and right child of ith node as l and r respectively.

Output format
Output space separated values of the nodes visible from right side of the tree from top to bottom.

Sample Input 1
6
10 15 25 12 40 16
4 -1 -1
1 5 3
5 6 -1
6 -1 -1
2 -1 -1
3 2 4

Sample Output 1
10 25 12

Explanation
The visible nodes from top to bottom are 10, 25 and 12.


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

vector<int> rightViewBinaryTree(TreeNode* root) {
    vector<int> result;
        if (root == NULL) {
            return result;
        }
        
        // Using level order traversal with queue
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            // Process all nodes at current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = q.front();
                q.pop();
                
                // If this is the last node of current level, add to result
                if (i == levelSize - 1) {
                    result.push_back(current->val);
                }
                
                // Add left child first, then right child
                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }
        }
        
        return result;
    
}

