class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(),cols = matrix[0].size();
        int l = 0, r = rows * cols ;
        //if(r==0){return matrix[0][0] == target;}
        while(l<r)
        {
            int m = l+(r-l)/2;
            cout<<m<<m/cols<<m%cols<<'\n';
            if(matrix[m/cols][m%cols]==target)
            {
                return 1;
            }
            else if(matrix[m/cols][m%cols]>target)
            {
                r=m;
            }
            else if(matrix[m/cols][m%cols]<target)
            {
                l=m+1;
            }
        }
        return 0;
    }
    
};
