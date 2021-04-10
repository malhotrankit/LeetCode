class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) 
    {
        int i,j,n,maximum=1;
        n=arr.size();
        int odd[n],even[n];
        
        for(i=0;i<n;i++)
        {
            odd[i]=1;
            even[i]=1;
        }
        
        for(i=1;i<n;i++)
        {
                if(arr[i]<arr[i-1])
                {
                    if(((odd[i-1]+1)%2==0)&&odd[i]<odd[i-1]+1)
                        odd[i]=odd[i-1]+1;
                    else
                        odd[i]=2;
                    if(((even[i-1]+1)%2==1)&&even[i]<even[i-1]+1)
                        even[i]=even[i-1]+1;
                    else
                        even[i]=1;
                    //i
                }
                if(arr[i]>arr[i-1])
                {
                    
                    if(((odd[i-1]+1)%2==1)&&odd[i]<odd[i-1]+1)
                        odd[i]=odd[i-1]+1;
                    else
                        odd[i]=1;
                    if(((even[i-1]+1)%2==0)&&even[i]<even[i-1]+1)
                        even[i]=even[i-1]+1;
                    else
                        even[i]=2;
                }
        }
        
        /*for(i=0;i<n;i++)
            printf("%d ",odd[i]);
        printf("\n");
        for(i=0;i<n;i++)
            printf("%d ",even[i]);*/
        
        return max(*max_element(odd, odd + n),*max_element(even, even + n));
    }
};