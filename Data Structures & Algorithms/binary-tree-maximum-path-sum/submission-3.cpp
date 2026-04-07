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
    int maxPathSum(TreeNode* root)
    {
        if(!root){return 0;}
        int m = root->val;
        h(root, m);
        return m;
    }
    int h(TreeNode* root,int &m)
    {
        if(!root){return 0;}
        int r = h(root->left ,m);
        int l = h(root->right,m);
        if(r<0)r=0;
        if(l<0)l=0;
        m = max(m,r+l+root->val);
        return root->val+max(l,r); 
    }
};
