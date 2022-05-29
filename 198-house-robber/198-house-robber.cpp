class Solution {
public:
    int rob(vector<int>& nums) 
    {
        vector<int> v;
        int i, j, n, max=0;
        n =  nums.size();
        v.reserve(n);
        for(i=0; i<n; i++)
        {
            v.push_back(nums[i]);
            for(j=0; j<i-1; j++)
            {
                if(nums[i] + v[j] > v[i])
                    v[i] = nums[i] +v[j];
            }
        }
        for(i=0; i<n; i++)
            if(max < v[i])
                max = v[i];
        
    return max;
    }
};