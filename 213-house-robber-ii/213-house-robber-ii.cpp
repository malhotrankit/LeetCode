class Solution {
public:
    int rob(vector<int>& v) 
    {
        int n,i,j,max;
        n=v.size();
        vector<int> nums(n,0);
        if(n<=3)
            return *max_element(v.begin(), v.end()); 
        
        nums[0]=v[0];
        nums[1]=v[1];
        nums[2]=v[2];
        nums[n-1]=v[n-1];
        v[2]=v[2]+v[0];
        for(i=3;i<n-1;i++)
        {
            nums[i]=v[i];
            if(v[i]+v[i-2]>v[i]+v[i-3])
            {
                v[i]=v[i]+v[i-2];
            }
            else
            {
                 v[i]=v[i]+v[i-3];
            }
        }
        nums[0]=0;
        for(i=3;i<n;i++)
        {
            if(nums[i]+nums[i-2]>nums[i]+nums[i-3])
            {
                nums[i]=nums[i]+nums[i-2];
            }
            else
            {
                 nums[i]=nums[i]+nums[i-3];
            }
        }
        v[n-1]=nums[n-1];
        
        max=0;
        for(i=n-4;i<n;i++)
            if(v[i]>max)
                max=v[i];
            
       
        return max;
        
    }
};