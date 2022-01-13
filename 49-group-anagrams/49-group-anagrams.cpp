class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        int i, array[26], j, n, len;
        n= strs.size(); 
        vector<string> vc;
        vc.assign(strs.begin(), strs.end());
        vector<vector<string>> vv;
        vector<string> v;
        char *s;
        
        for(i=0;i<n;i++)
        {
            len= strs[i].length();
            s=&strs[i][0];
            sort(s,s+len);   
        }
        
        /*for(i=0;i<n;i++)
            cout<<" "<<strs[i];*/
        
        for(i=0;i<n;i++)
        {
            if(strs[i].compare("000") == 0)
                continue;
            v.push_back(vc[i]);
            for(j=i+1;j<n;j++)
            {
                    if(strs[i].compare(strs[j]) == 0)
                    {
                        v.push_back(vc[j]);
                        strs[j]= "000";
                    }
            }
            strs[i] = "000";
            vv.push_back(v);
            v.clear();
        }
        
        return vv;
    }
};