class Solution 
{
public:
    inline vector<int> dailyTemperatures(vector<int>& T) 
    {
        int n,i,j,minimum;
        vector<int> v;
        n= T.size();
        int arr[101];
        
        for(i=0;i<101;i++)
            arr[i]= INT_MAX;
        
        for(i=n-1;i>=0;i--)
        {
            minimum= INT_MAX;
            for(j=T[i]+1;j<=100;j++)
            {
                if(arr[j]!= INT_MAX && minimum>arr[j])
                {
                    minimum= arr[j];
                }
            }
            arr[T[i]]= i;
            
            if(minimum!=INT_MAX)
                v.push_back(minimum-i);
            else
                v.push_back(0);
        }
        
        reverse(v.begin(),v.end());
        return v;
    }
};