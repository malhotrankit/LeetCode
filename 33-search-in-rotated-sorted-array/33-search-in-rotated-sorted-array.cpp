class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int first, last , mid, n, flag=1, pos;
        n= nums.size();
        last= n-1;
        first= 0;
        
        while(flag==1)
        {
            mid= (first+last)/2;
            if(nums[first]>nums[last])
            {
                first= mid+1;
            }
            else
            {
                if(first>0&&nums[first-1]<nums[first])
                    first = first-1;
                else
                    flag=0;
            }
        }
        //cout<<first;
        pos = lower_bound(nums.begin(), nums.begin()+first, target)-nums.begin();
        if(pos<n&&nums[pos]==target)
            return pos;
        pos = lower_bound(nums.begin()+first, nums.end(), target)-nums.begin();
        //cout<<" p "<<pos;
        if(pos<n&&nums[pos]==target)
            return pos;
        return -1;
    }
};