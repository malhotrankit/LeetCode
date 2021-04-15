class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int array[5001],i,j,n,max,k;
        n = prices.size();
        array[0]=0;
        for(i=1 ; i<n; i++)
        {
            array[i]=0;
            for(j=i-1;j>=0;j--)
            {
                if(prices[i]-prices[j]>0)
                {
                    k=j-2;
                    if(k<0)
                        k=0;
                    if(array[k]+prices[i]-prices[j]>array[i])
                        array[i]=array[k]+prices[i]-prices[j];
                }
                    
            }
            if(array[i]<array[i-1])
                array[i]=array[i-1];
            
        }
        return array[n-1];
        
    }
};