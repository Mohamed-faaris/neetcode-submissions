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
    int kthSmallest(TreeNode* root, int k) 
    {
        int r = 0,res = 0;
        ino(root,k,r,res);
        return res;
    }
    void ino(TreeNode* root, int k,int &r,int &res)
    {
        if(root&&!res)
        {
            ino(root->left ,k,r,res);
            r++;
            if(k==r){res = root->val;}
            ino(root->right,k,r,res);
        }
    }
};
