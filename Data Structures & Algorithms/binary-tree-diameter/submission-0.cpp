/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int m = 0;
        maxDepth(root,m);
        return m;
    }
    int maxDepth(TreeNode* root,int &m) {
        if(root==NULL)
        {
            return 0;
        }
        int l = maxDepth(root->left,m);
        int r = maxDepth(root->right,m);
        m = max(m,l+r);
        return max(l,r)+1;
    }
};
