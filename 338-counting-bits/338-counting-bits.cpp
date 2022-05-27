class Solution {
public:
    vector<int> countBits(int num) {
        int i,j=0,flag=1;
        vector<int> v(num+1);
        if(num==0)
            return v;
        v[0]=0;
        v[1]=1;
        while(flag)
        {
            if(num>=pow(2,j))
                v[pow(2,j)]=1;
            else
                flag=0;
            j++;
        }
        j=0;
        for(i=2; i<=num; i++)
        {
            if(v[i]==1)
                j++;
            if(v[i]==0)
            {
                v[i]=v[i-pow(2,j-1)]+1;
            }
            if(i+pow(2,j)<=num)
            {
                v[i+pow(2,j)]=v[i];
            }
            
        }
        return v;
    }
};