class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n=nums.size();
        int hm[200001],i,j, val;
        vector<int> v;
        set<vector<int>> s;
        
        for(i=0;i<200001;i++)
              hm[i]=-1;
        
        for(i=0;i<n;i++)
            hm[100000+nums[i]]=i;
        
        for(i=0; i<n-1; i++)
        {
            for(j=i+1; j<n; j++)
            {
                if(nums[i]+nums[j]>=-100000&&nums[i]+nums[j]<=100000)
                {
                    val=abs(100000-(nums[i]+nums[j]));
                    v.clear();
                    if(hm[val]!=-1&&hm[val]!=i&&hm[val]!=j)
                    {
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[hm[val]]);
                        sort(v.begin(),v.end());
                        s.insert(v);
                    }
                }
            }
        }
        
        vector<vector<int>> ans(s.begin(),s.end());
        
        return ans;
        
    }
};