class Solution {
public:
    int maxProfit(vector<int>& p) {
        int l=0,r=1,m=0;
        for(;r<p.size();r++)
        {
            if(p[l]>p[r])
            {
                l=r;
            }
            m=max(m,p[r]-p[l]);
        }
        return m;
    }
};
