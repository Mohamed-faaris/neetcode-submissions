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
    TreeNode* buildTree(vector<int>& p, vector<int>& i) {
        return b(p,i,0,p.size());
    }
    TreeNode* b(vector<int>& pre, vector<int>& ino,int l ,int r)
    {
        int m;
        if(l<r)
        {
            m = index(pre, ino, l, r);
            TreeNode* temp = new TreeNode(ino[m]); 
            temp->left = b(pre, ino, l , m);
            temp->right= b(pre, ino, m+1 , r);
            return temp;
        }
        return 0;
    }
    int index(vector<int>& pre, vector<int>& ino,int &l ,int &r)
    {
        for(int p:pre)
            {
                for(int i = l;i<r;i++)
                {
                    if(ino[i]==p) return i;
                }
            }
        return -1;
    }
    
};
    