class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        int i,j,maximum=0,n;
        n=s.length();
        int dp[n+1][n+1];
        
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                dp[i][j]=0;
            }
            dp[i][i]=1;
        }
        
        for(i=1;i<=n;i++)
        {
            maximum=dp[i][i];
            for(j=i-1;j>=1;j--)
            {
                if(s[i-1]==s[j-1])
                {
                    dp[i][j]=dp[i-1][j+1]+2;
                }
                else
                {
                    dp[i][j]=max(dp[i][j+1],dp[i-1][j]);
                }
                if(maximum<dp[i][j])
                {
                    maximum=dp[i][j];
                }
            }
        }
        
        /*for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                printf("%d ",dp[i][j]);
            }
            printf("\n");
        }*/
        
        return maximum;
        
    }
};