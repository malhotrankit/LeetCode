class Solution {
public:
    int knightDialer(int n) 
    {
        int dp[n+1][10],sum=0,i,j,k;
        int graph[10][3]={{6,4,-1}, {8,6,-1}, {9,7,-1}, {8,4,-1}, {9,0,3}, {-1,-1,-1}, {0,7,1}, {2,6,-1}, {3,1,-1}, {2,4,-1}};
        
        if(n==1)
            return 10;
        
        for(i=0;i<10;i++)
            dp[2][i]=2;
        dp[2][4]=3;dp[2][6]=3;dp[2][5]=0;
        
        for(i=3;i<=n;i++)
        {
            for(j=0;j<10;j++)
            {
                dp[i][j]=0;
                for(k=0;k<3;k++)
                {
                    if(graph[j][k]!=-1)
                        dp[i][j]=(dp[i][j]+dp[i-1][graph[j][k]])%1000000007;
                }
            }
        }

        for(i=0;i<10;i++)
            sum=(sum+dp[n][i])%1000000007;
        return sum;
    }
};