class Solution {
public:
    int integerBreak(int n) {
        int array[59],i,j,maxi;
        array[1]=1;
        for(i=2;i<=n;i++)
            array[i]=-1;
        for(i=2;i<=n;i++)
        {
            for(j=i/2;j>=1;j--)
            {
                maxi=max(j*(i-j),array[j]*array[i-j]);
                maxi=max(maxi,j*array[i-j]);
                maxi=max(maxi,array[j]*(i-j));
                if(maxi>array[i])
                    array[i]=maxi;
            }
        }
        return array[n];
    }
};