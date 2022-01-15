class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int i=0, j=0, ele, n, pos1=-1, pos2=-1;
        n= nums.size();
        //cout<<n;
        for(i=n-1;i>0;i--)
        {
            for(j=i-1;j>=0;j--)
            {
                if(nums[i]>nums[j])
                {
                    if(j>pos2)
                    {
                        pos1=i;
                        pos2=j;
                    }
                }
            }
        }
        if(pos1 == -1)
             sort(nums.begin(), nums.end());
        else
        {
            ele= nums[pos1];
            nums[pos1]= nums[pos2];
            nums[pos2]= ele;
            sort(nums.begin() + pos2 + 1, nums.end());
        }
    }
   
};