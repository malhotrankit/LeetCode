class Solution {
public:
    inline int diagonalSum(vector<vector<int>>& mat) 
    {
        int i,n,sum=0;
        n=mat.size();
        
        for(i=0;i<n;i++)
        {
                //sum+=mat[i][i];
            sum+=mat[i][n-i-1]+mat[i][i];
        }
        if(n%2==1)
            sum-=mat[n/2][n/2];
        return sum;
        
    }
};