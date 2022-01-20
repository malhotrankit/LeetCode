class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n,i,j, len= INT_MIN, minimum, maximum, flag=0;
        n= s.length();
        int arr[95];
        
        if(n==0)
            return 0;
        
        for(i=0;i<95;i++)
            arr[i]=INT_MAX;
        
        for(i=0;i<n;i++)
        {
            if(arr[s[i]-32]==INT_MAX)
            {
                arr[s[i]-32]=i;
                if(i==n-1)
                    flag=1;
            }    
            else
            {
                minimum= INT_MAX;
                for(j=0;j<95;j++)
                {
                    if(minimum>arr[j])
                        minimum=arr[j];
                }
                if(len<i-minimum)
                   len= i-minimum;
                for(j=0;j<95;j++)
                {
                    if(arr[j]<arr[s[i]-32])
                        arr[j]=INT_MAX;
                }
                arr[s[i]-32]=i;
            }
            //cout<<len<<" "; 
        }
        
        if(flag==1)
        {
            maximum= INT_MIN;
            minimum= INT_MAX;
            for(j=0;j<95;j++)
            {
                if(minimum>arr[j])
                    minimum=arr[j];
                if(maximum<arr[j])
                    maximum= arr[j];
            }
            if(len<i-minimum)
                len= i-minimum;
        }
        
        return len;    
    }
};