class Solution 
{
public:
    vector<int> findOrder(int numc, vector<vector<int>>& pre) 
    {
        int dep[numc], i, ele;
        unordered_map<int, vector<int>> um;
        queue<int> q;
        vector<int> v,p;
        
        for(i=0;i<numc;i++)
            dep[i]=0;
        
        for(i=0;i<pre.size();i++)
        {
            dep[pre[i][0]]++;
            um[pre[i][1]].push_back(pre[i][0]);
        }
        
        for(i=0;i<numc;i++)
        {
            if(dep[i]==0)
            {
                q.push(i);
                v.push_back(i);
            }
        }
        
        while(!q.empty())
        {
            ele = q.front();
            q.pop();
            for(i=0;i<um[ele].size();i++)
            {
                dep[um[ele][i]]--;
                if(dep[um[ele][i]]==0)
                {
                    q.push(um[ele][i]);
                    v.push_back(um[ele][i]);
                }
            }
            
        }
        if(v.size()!=numc)
            return p;
        return v;
    }
};