class Solution 
{
public:
    bool canFinish(int numc, vector<vector<int>>& pre) 
    {
        int i, n, ele, count=0;
        unordered_map<int, vector<int>> um;
        unordered_map<int, int> indegree;
        //vector<int> v;
        queue<int> q;
        n = pre.size();
        
        for(i=0;i<numc;i++)
            indegree[i] = 0;
        
        for(i=0;i<n;i++)
        {
            um[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
        
        for(i=0;i<numc;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                //v.push_back(i);
                count++;
            }
        }
        
        while(!q.empty())
        {
            ele = q.front();
            q.pop();
            
            for(i=0;i<um[ele].size();i++)
            {
                indegree[um[ele][i]]--;
                if(indegree[um[ele][i]]==0)
                {
                    q.push(um[ele][i]);
                    //v.push_back(um[ele][i]);
                    count++;
                }
            }
        }
        
        if(count==numc)
            return true;
        
        return false;
    }
};