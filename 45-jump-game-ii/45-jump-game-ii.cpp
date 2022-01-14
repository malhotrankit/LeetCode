class Solution 
{
public:
    int jump(vector<int>& nums) 
    {
        int n, i, j, flag=0;
        n = nums.size();
        vector<int> v(n);
        
        for(i=0;i<n;i++)
            v[i]=0;
        
        for(i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                for(j=i+1;j<=i+nums[i];j++)
                {
                    if(j<n&&v[j]==0)
                        v[j] = v[i] + 1;
                    if(j==n-1)
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==1)
                break;
        }
        return v[n-1];
    }
};