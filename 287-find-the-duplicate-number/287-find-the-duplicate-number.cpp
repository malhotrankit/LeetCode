class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int n,i,ele;
        n=nums.size();
        --n;
        
        for(i=0;i<n+1;i++)
        {
            if(nums[i]<=n)
            {
                
                if(nums[nums[i]-1]<=n)
                    nums[nums[i]-1]+=n;
                else
                    return nums[i];
            }
            else
            {
                if(nums[nums[i]-n-1]<=n)
                    nums[nums[i]-n-1]+=n;
                else
                    return (nums[i]-n);
            }
        }
        
        for(i=0;i<n+1;i++)
        {
            if(nums[i]>n)
                nums[i]-=n;
        }
        /*for(i=0;i<n+1;i++)
            printf("%d ",nums[i]);*/
        return ele;
    }
};