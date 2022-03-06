class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int red=0, white=0, blue=0, n, i;
        n= nums.size();
        
        for(i=0;i<n;i++)
        {
            if(nums[i]==0)
                red++;
            else if(nums[i]==1)
                white++;
            else
                blue++;
        }
        
        i=0;
        for(;red>0;red--)
            nums[i++]=0;
        for(;white>0;white--)
            nums[i++]=1;
        for(;blue>0;blue--)
            nums[i++]=2;
        
    }
};