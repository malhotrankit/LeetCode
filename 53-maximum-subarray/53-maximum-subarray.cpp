class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sum =0, maxsum=INT_MIN, i, n;
        n = nums.size();
        for(i=0; i<n; i++)
        {
            
            sum= sum + nums[i];
            if(maxsum < sum)
                maxsum = sum;
            if(sum < 0)
                sum = 0;
        }
        return maxsum;
    }
};