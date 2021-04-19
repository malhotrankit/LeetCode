class Solution 
{
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        int dp[366],i,minimum,n,k;
        n=days.size();
        for(i=0;i<=365;i++)
            dp[i]=0;
        for(i=0;i<n;i++)
            dp[days[i]]=costs[0];
        for(i=1;i<=365;i++)
        {
            if(dp[i]==0)
                dp[i]=dp[i-1];
            else
            {
                minimum=dp[i]+dp[i-1];
                
                k=i-7;
                if(k<0)
                    k=0;
                minimum=min(minimum,dp[k]+costs[1]);
                
                k=i-30;
                if(k<0)
                     k=0;
                minimum=min(minimum,dp[k]+costs[2]);
                
                dp[i]=minimum;
            }
        }
        return dp[365];
    }
};