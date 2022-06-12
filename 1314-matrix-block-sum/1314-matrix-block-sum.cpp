class Solution 
{
    public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) 
    {
        int m,n,i,j,p,q,r,s;
        m=mat.size();
        n=mat[0].size();
        vector<vector<int>> vec( m+1 , vector<int> (n+1, 0));
        
        for(j=0;j<n;j++)
            if(j>0)
                vec[1][j+1]=mat[0][j]+vec[1][j];
            else
                vec[1][j+1]=mat[0][j];
        
        for(i=0;i<m;i++)
            if(i>0)
                vec[i+1][1]=mat[i][0]+vec[i][1];
            else
                vec[i+1][1]=mat[i][0];
        
        for(i=2;i<=m;i++)
            for(j=2;j<=n;j++)
                vec[i][j] = vec[i-1][j] + vec[i][j-1]  - vec[i-1][j-1] + mat[i-1][j-1];
        
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                p =  i+K;
                q =  j+K;
                r =  i-K-1;
                s =  j-K-1;
                if(p>m)
                    p=m;
                if(q>n)
                    q=n;
                if(r<0)
                    r=0;
                if(s<0)
                    s=0;
                mat[i-1][j-1]= vec[p][q] - vec[r][q] - vec[p][s] + vec[r][s];
            }
        }
        
        return mat;
    }
};  