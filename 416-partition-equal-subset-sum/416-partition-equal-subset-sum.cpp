class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int n,i,j,sum=0;
        n=nums.size();
        for(i=0;i<n;i++)
            sum=sum+nums[i];
        if(sum%2!=0)
            return false;
        else
        {
            vector<int> v(sum/2+1,0);
            v[0]=-1;
            for(i=0;i<n;i++)
            {
                for(j=0;j<=sum/2;j++)
                {
                    if(v[j]!=0&&v[j]!=i+1&&j+nums[i]<=sum/2)
                    {
                        if(v[j+nums[i]]==0)
                            v[j+nums[i]]=i+1;
                    }
                    
                }
            }
            if(v[sum/2]>=1)
                return true;
            else
                return false;
        }
    }
};