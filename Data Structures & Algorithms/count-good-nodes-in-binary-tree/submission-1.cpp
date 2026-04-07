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
    int goodNodes(TreeNode* root) {
        return c(root,INT_MIN);
    }
    int c(TreeNode* root,int m)
    {
        if(root)
        {  
            int i = root->val>=m;
            m = max(m,root->val);
            return c(root->left,m)+c(root->right,m)+i;
        }
        return 0;
    }
};
