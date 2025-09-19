Problem Description
Given postorder and inorder traversal of a tree, construct the binary tree and return its root. Note: You may assume that duplicates do not exist in the tree.

Input format
First line contains N, number of elements in the tree.
Next line contains N space separated integers, denoting postorder.
Next line contains N space separated integers, denoting inorder.

Output format
Print two lines, first line contains N space separated integers denoting postorder.
Second line contains N space separated integers, denoting inorder.
Note: You just have to return the root of the tree. The input/output is already handled.

Sample Input 1
5
10 4 5 7 8
8 10 4 7 5

Sample Output 1
10 4 5 7 8
8 10 4 7 5


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

TreeNode* makeTree(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int poststart, int postend, map<int, int>& inmap)
{
    if(poststart>postend || instart>inend)
        return NULL;

    TreeNode* root = new TreeNode(postorder[postend]);

    int inroot = inmap[root->val];
    int inval = inroot - instart;

    root->left = makeTree(inorder, instart, inroot-1, postorder, poststart, poststart+inval-1, inmap);
    root->right = makeTree(inorder, inroot+1, inend, postorder, poststart+inval, postend-1, inmap);

    return root;
}

TreeNode* constructBinaryTreeFromPostorderAndInorderTraversal(vector<int> &postorder, vector<int> &inorder) {
    int n = inorder.size();
    map<int,int> inmap;
    for(int i=0; i<n; i++)
    {
        inmap[inorder[i]] = i;
    }
    TreeNode* root = makeTree(inorder, 0, n-1, postorder, 0, n-1, inmap);
    return root;
}
