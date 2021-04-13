class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int n,i,j;
        n=s.length();
        int dp[n+1];
        
        for(i=0;i<=n;i++)
            dp[i]=0;
        
        for(i=1;i<=n;i++)
        {
            for(j=i;j>=1;j--)
            {
                if(std::find(wordDict.begin(), wordDict.end(), s.substr(j-1,i-j+1)) != wordDict.end()&&dp[i]<dp[j-1]+i-j+1)
                {
                    dp[i]=dp[j-1]+i-j+1;
                }
            }
        }
        
        /*for(i=1;i<=n;i++)
            printf("%d ",dp[i]);*/
        
        if(dp[n]==n)
            return true;
        return false;
    }
};