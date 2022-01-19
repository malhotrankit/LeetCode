class Solution 
{
public:
    inline vector<int> findAnagrams(string s, string p) 
    {
        int i,j,n,m,count;
        n= s.length();
        m= p.length();
        int arr1[26], arr2[26];
        vector<int> v;
        
        for(i=0;i<26;i++)
        {
            arr1[i]=0;
            arr2[i]=0;
        }
        
        for(i=0;i<m;i++)
            arr2[p[i]-97]++;
        
        for(i=0;i<=n-m;i++)
        {
            count=0;
            
            for(j=i;j<i+m;j++)
                arr1[s[j]-97]++;

            for(j=0;j<26;j++)
            {
                if(arr1[j]==arr2[j])
                    count++;
                arr1[j]=0;
            }
            
            if(count==26)
                v.push_back(i);
        }
        return v;
    }
};