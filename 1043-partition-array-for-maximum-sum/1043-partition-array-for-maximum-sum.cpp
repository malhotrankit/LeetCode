class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        int i,j,n,maximum,m;
        n=arr.size();
        vector<int> dp(n+1,0);
        for(i=0 ; i<n; i++)
        {
            maximum = arr[i];
            for(j=i;j>i-k&&j>=0;j--)
            {
                if(arr[j]>maximum)
                    maximum = arr[j];
                if(maximum * (i-j+1) + dp[j] >dp[i+1])
                    dp[i+1]=maximum * (i-j+1) + dp[j];
            }
            //printf("\n");
        }
        //for(i=0;i<=n;i++)
           // printf("%d ",dp[i]);
        return dp[n];
        
    }
};