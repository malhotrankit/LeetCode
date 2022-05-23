class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n,i,j,array[10001];
        array[0]=0;
        n=coins.size();
        for(i=1;i<=amount;i++)
            array[i]=-1;
    
        for(i=0;i<=amount;i++)
        {
            for(j=0;j<n;j++)
            {
                if(array[i]==-1)
                {
                    if(i>=coins[j]&&array[i-coins[j]]>=0)
                    {
                        array[i]=array[i-coins[j]]+1;
                    }
                }
                else
                {
                    if(i>=coins[j]&&array[i-coins[j]]>=0&&1+array[i-coins[j]]<array[i])
                    {
                         array[i]=1+array[i-coins[j]];
                    }
                }
                
            }
        }
        return array[amount];
    }
};