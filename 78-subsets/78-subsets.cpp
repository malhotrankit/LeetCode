class Solution 
{
public:
    vector<vector<int>> v;
    vector<int> m;
    int n;
    
    inline void permutation(vector<int> &nums, int i, int j)
    {
        v.push_back(m);
        
        for(;i<n;i++)
        {
            for(;j<n;j++)
            {
                m.push_back(nums[j]);
                    
                permutation(nums, j, j+1);
                    
                m.pop_back();   
            }
        }
    }
    
    inline vector<vector<int>> subsets(vector<int>& nums) 
    {
        n = nums.size();
        permutation(nums, 0, 0);
        return v;
    }
};