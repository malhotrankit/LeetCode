/*class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        int i, pos, j;
        vector<int> v2;
        vector<pair<int,int>> v;
        for(i=0;i<s.length();i++)
        {
            pos=-1;
            for(j=i+1;j<s.length();j++)
            {
                if((s[i]==s[j])&&(s[i]!='0'))
                {
                    pos=j;
                    s[j]='0';
                }
            }
            if(pos!=-1)
                v.push_back(make_pair(i,pos));
            else
                if(s[i]!='0')
                    v.push_back(make_pair(i,i));
        }
        
        for(i=0;i<v.size();i++)
        {
            for(j=i+1;j<v.size();j++)
            {
                if((v[i].first!=-1)&&(v[i].second!=-1)&&(v[j].first!=-1)&&(v[j].second!=-1))
                {
                    if(v[i].second>v[j].first&&v[i].second<v[j].second)
                    {
                        v[i].second=v[j].second;
                        v[j].first=-1;
                        v[j].second=-1;
                    }
                    if(v[i].second>v[j].first&&v[i].second>v[j].second)
                    {
                        v[j].first=-1;
                        v[j].second=-1;
                    }
                }
            }
            if((v[i].first!=-1)&&(v[i].second!=-1))
                v2.push_back(v[i].second-v[i].first+1);
        }
        return v2;
    }
};*/






class Solution 
{
public:
    vector<int> partitionLabels(string st) 
    {
        int um[26];
        vector<int> v;
        int i, maxi=0, s=0;
        
        for(i=0;i<st.length();i++)
            um[st[i]-97]=i;

        for(i=0;i<st.length();i++)
        {
            maxi= max(maxi,um[st[i]-97]);
            if(maxi==i)
            {
                v.push_back(maxi-s+1);
                s= i+1;
            }
            
        }
        
        return v;
    }
};