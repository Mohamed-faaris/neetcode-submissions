class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r=0,l=0,m=0,max_l=0;
        unordered_set<int> set;
        for(;r<s.size();r++)
        {
            while(set.find(s[r])!=set.end())
            {
                set.erase(set.find(s[l]));
                l++;
                m--;
            }
            set.insert(s[r]);
            m++;
            max_l=max(max_l,m);
            cout<<s[r]<<m;
        }
        return max_l;
    }
};
