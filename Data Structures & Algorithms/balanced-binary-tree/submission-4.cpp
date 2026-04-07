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
    bool isBalanced(TreeNode* root) {
        bool b = true;
        maxDepth(root,b);
        return b;        
    }
    int maxDepth(TreeNode* root,bool &m) {
        if(!m){return 0;}
        if(root==NULL)
        {
            return 0;
        }
        int l = maxDepth(root->left,m);
        int r = maxDepth(root->right,m);
        m = m&&abs(l-r)<2;
        return max(l,r)+1;
    }
};
