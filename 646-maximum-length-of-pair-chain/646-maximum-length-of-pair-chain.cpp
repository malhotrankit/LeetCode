class Solution {
public:
    inline static bool sortcol( const vector<int>& v1, const vector<int>& v2 ) 
    { 
        return v1[1] < v2[1]; 
    } 
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        int i,j,n,max;
        n=pairs.size();
        sort(pairs.begin(), pairs.end(),sortcol); 
        vector<int> v(n,1);
        for(i=1;i<n;i++)
        {
            max=v[i];
            for(j=i-1;j>=0;j--)
            {
                if(pairs[i][0]>pairs[j][1])
                {
                    if(max<v[i]+v[j])
                        max=v[i]+v[j];
                }
            }
            v[i]=max;
        }
        /*for(i=0;i<n;i++)
            printf("%d ",v[i]);*/
        return *max_element(v.begin(),v.end());
    }
};