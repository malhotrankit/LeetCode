class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int i,j,n,maximum=1;
        n=nums.size();
        int dp[n];
        
        for(i=0;i<n;i++)
            dp[i]=1;
        
        for(i=1;i<n;i++)
        {
            for(j=i-1;j>=0;j--)
            {
                if(nums[i]>nums[j]&&dp[i]<dp[j]+1)
                    dp[i]=dp[j]+1;
                if(dp[i]>maximum)
                    maximum=dp[i];
            }
        }
        
        /*for(i=0;i<n;i++)
            printf("%d ",dp[i]);*/
        
        return maximum;
    }
};