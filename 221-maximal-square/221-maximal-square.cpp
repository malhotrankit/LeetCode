class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int i,j,maximum=0,n,m,minimum;
        m=matrix.size();
        n=matrix[0].size();
        int dp[m][n];
        
        if(matrix[0][0]=='1')
            maximum=1;
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                dp[i][j] = matrix[i][j]- 48;
            }
        }
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(dp[i][j]!=0&&i-1>=0&&j-1>=0)
                {
                    minimum=min(min(dp[i][j-1],dp[i][j-1]),min(dp[i-1][j],dp[i-1][j]));
                    dp[i][j]=min(minimum,min(dp[i-1][j-1],dp[i-1][j-1]))+1;
                    if(maximum<dp[i][j])
                        maximum=dp[i][j];
                }
                
                if(dp[i][j]!=0&&i-1>=0&&j-1<0)
                {
                    dp[i][j]=1;
                    if(maximum<dp[i][j])
                        maximum=dp[i][j];
                }
                
                if(dp[i][j]!=0&&i-1<0&&j-1>=0)
                {
                    dp[i][j]=1;
                    if(maximum<dp[i][j])
                        maximum=dp[i][j];
                }
            }
            
        }

        return maximum*maximum;   
    }
};