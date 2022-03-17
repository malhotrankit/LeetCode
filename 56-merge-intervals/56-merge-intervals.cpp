class Solution 
{
public:
    
    inline static bool sortcol( const vector<int>& v1, const vector<int>& v2 ) 
    { 
        return v1[1] < v2[1]; 
    }
    
    inline vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> v;
        unsigned i, k=1,  n;
        n=intervals.size();
        sort(intervals.begin(), intervals.end(), sortcol);
        
        v.push_back(intervals[0]);
        
        for(i=1; i<n; )
        {
            if(k>0&&v[k-1][1]>=intervals[i][0])
            {
                if(v[k-1][0]<intervals[i][0])
                     intervals[i][0]= v[k-1][0];
                v.pop_back();
                --k;
            }
            else
            {
                v.push_back(intervals[i]);
                ++i;
                ++k;
            }
        }
        
        /*for(i=1; i<n;)
        {
            if(i>0&&intervals[i-1][1]>=intervals[i][0])
            {
                if(intervals[i][0]>intervals[i-1][0])
                     intervals[i][0]= intervals[i-1][0];
                intervals.erase(intervals.begin()+i-1);
                --i;
                --n;
            }
            else
                ++i;
        }
        
        for(unsigned i=0; i<intervals.size(); i++)
            printf("[%d,%d] ",intervals[i][0],intervals[i][1]);*/
        
        return v;
    }
};