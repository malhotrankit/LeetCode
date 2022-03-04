class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int l, r, n;
        vector<int> v;
        n=nums.size();
        l = std::lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        r = std::upper_bound(nums.begin(), nums.end(), target)-nums.begin();
        //cout<<l<<" "<<r;
        if(l<n&&nums[l]==target)
            v.push_back(l);
        else
            v.push_back(-1);
        if(r-1>=0&&nums[r-1]==target)
            v.push_back(r-1);
        else
            v.push_back(-1);
        return v;
    }
};