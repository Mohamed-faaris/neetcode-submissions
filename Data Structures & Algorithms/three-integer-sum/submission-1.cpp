class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int i = 0,j = 1,k = nums.size()-1;
        if(nums.size()<3) return res;
        cout<<(i<nums.size()-2)<<"\n";
        for(;i<nums.size()-2;i++)
        {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            if(nums[i]>0) break;
            j = i+1;
            k = nums.size()-1;
            while(j<k)
            {
                //cout<<i<<j<<k<<nums[i] << nums[j] << nums[k]<<"\n";
                int sum = nums[i] + nums[j] + nums[k];
                
                if(sum == 0) 
                {
                    res.push_back({nums[i], nums[j], nums[k]});
                    //cout<<nums[i] << nums[j] << nums[k];
                    while(j < k && nums[j] == nums[j + 1]) j++;
                    while(j < k && nums[k] == nums[k - 1]) k--;
                    j++;k--;
                }
                else if(sum<0) {j++;}
                else if(sum>0) {k--;}
            }
            //while(i > 0 && nums[i] == nums[i - 1]) {i++;}
        }
        return res;
    }
};