class Solution 
{
public:
    inline vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        int n, i, maximum, ele;
        n= nums.size();
        unordered_map<int, int> umap;
        std::pair<std::unordered_map<int,int>::iterator,bool> ret;
        vector<int> v;
        
        for(i=0;i<n;i++)
        {
            ret= umap.insert(make_pair(nums[i], 1));
            if(ret.second==false)
                umap[nums[i]]++;
        }
        
        while(k--)
        {
            maximum= INT_MIN;
            for (auto itr = umap.begin(); itr != umap.end(); ++itr)
            {
                if(maximum<itr->second)
                {
                    maximum = itr->second;
                    ele= itr->first;
                }            
            }
            v.push_back(ele);
            umap.erase(ele);
        }
        
        return v;
    }
};