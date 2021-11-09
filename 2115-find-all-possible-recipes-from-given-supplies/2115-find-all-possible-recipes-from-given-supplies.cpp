class Solution 
{
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) 
    {
        int i, n, j;
        set<string> s;
        vector<string> v;
        n = sup.size();
        unordered_map <string, int> indegree;
        unordered_map <string,vector<string>> graph;
        queue<string> q;
        string st;
        
        for(i=0;i<n;i++)
        {
            s.insert(sup[i]);
            indegree[sup[i]] = 0;
        }
        
        n = ing.size();
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<ing[i].size();j++)
            {
                if(s.find(ing[i][j]) == s.end())
                {
                    graph[ing[i][j]].push_back(rec[i]);
                    indegree[rec[i]]++;
                }
            }
        }
            
        for(i=0;i<n;i++)
        {
            if(indegree[rec[i]]==0)
            {
                q.push(rec[i]);
                v.push_back(rec[i]);
            }
            
        }
            
        while(!q.empty())
        {
            st = q.front();
            q.pop();
            
            for(i=0;i<graph[st].size();i++)
            {
                indegree[graph[st][i]]--;
                if(indegree[graph[st][i]]==0)
                {
                    v.push_back(graph[st][i]);
                    q.push(graph[st][i]);
                }
            }
            
        }
            
        return v;    
    }
};