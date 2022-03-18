class Solution 
{
public:
    int dp[18][18], n;
    vector<vector<string>> vv;
    vector<string> v;
    
    inline void permutation(string s, int i, int j, int slen)
    {
        if(slen==n)
        {
            vv.push_back(v);
        }
        else
        {
            for(;i<=n;i++)
            {
                if(dp[i][j]!=0)
                {
                    v.push_back(s.substr(j-1, dp[i][j]));
                    
                    permutation(s, j + dp[i][j], j + dp[i][j], slen + dp[i][j]);
                
                    v.pop_back();
                }
            }
        }
    }
    
    inline vector<vector<string>> partition(string s) 
    {
        int i,j;
        n=s.length();
        
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
            for(j=1;j<i;j++)
            {
                if(s[i-1]==s[j-1]&&i-j-1==dp[i-1][j+1])
                {
                    dp[i][j]=i-j+1;
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        
        permutation(s, 1, 1, 0);
        
        /*for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                printf("%d ",dp[i][j]);
            }
            printf("\n");
        }*/
        
        return vv;   
    }
};