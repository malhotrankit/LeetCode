class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n, i, count=0, prod=1;
        n= nums.size();
        vector<int> v;
        //v.reserve(n);
        
        for(i=0;i<n;i++)
        {
            if(nums[i]==0)
                count++;    
            v.push_back(nums[i]);
        }
        
        if(count>1)
        {
            for(i=0;i<n;i++)
                v[i]=0;
        }
        else
        {
            if(count==0)
            {
                for(i=1;i<n;i++)
                    nums[i]=nums[i]*nums[i-1]; 
                for(i=n-2;i>=0;i--)
                    v[i]=v[i]*v[i+1];
                v[0]=v[1];
                for(i=1;i<n-1;i++)
                    v[i]=v[i+1]*nums[i-1];
                v[n-1]=nums[n-2];
            }
            else
            {
                for(i=0;i<n;i++)
                {
                    if(nums[i]!=0)
                        prod=prod*nums[i];
                }
                for(i=0;i<n;i++)
                {
                    if(nums[i]!=0)
                        v[i]=0;
                    else
                        v[i]=prod;
                }
            }
        }
        return v;
    }
};