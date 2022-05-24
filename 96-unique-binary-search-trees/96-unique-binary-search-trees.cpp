class Solution {
public:
    int numTrees(int n) {
        int i,j,sum;
        vector<int> v(n+1,0);
        v[0]=1;
        v[1]=1;
        for(i=2 ; i<=n; i++)
        {
            sum=0;
            for(j=i-1;j>i/2;j--)
            {
                sum = sum + 2 * v[j] * v[i-j-1];
            }
            if(i%2==0)
                sum = sum + 2 * v[i/2] * v[i/2-1];
            else
                sum = sum + v[i/2] * v[i/2];
            v[i]=sum;
        }
        return v[n];
        
    }
};