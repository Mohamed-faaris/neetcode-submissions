class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> set;
        h(res,nums,0,set);
        return res;
    }
    void h(vector<vector<int>> &res,vector<int>& nums,int i,vector<int> set)
    {
        if(i<nums.size())
        {
            h(res,nums,i+1,set);
            set.push_back(nums[i]);
            h(res,nums,i+1,set);
            return;
        }
        res.push_back(set);
    }
};
