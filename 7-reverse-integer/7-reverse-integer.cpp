class Solution 
{
public:
    int reverse(int x) 
    {
        int i,flag=0,neg = 1,count2=0,count=0;
        int mini[]= {2,1,4,7,4,8,3,6,4,8};
        int maxi[]= {2,1,4,7,4,8,3,6,4,7};
        
        if(x==-2147483648)
            return 0;
        
        if(x<0)
        {
            neg=-1;
            x= x*-1;
        }
        
        vector<int> v;
        
        for(i=x;i>0;i=i/10)
        {
            count2++;
            if(i%10==0&&flag==0)
            {
                count++;
            }
            else
            {
                flag=1;
            }
        }
        
        v.resize(count2-count);
        
        for(i=0;i<count2;i++)
        {
            if(i>=count)
                v[i-count]=x%10;
            x=x/10;
        }
        
        if(v.size()==10)
        {
            if(neg==-1)
            {
                for(i=0;i<v.size();i++)
                {
                    if(v[i]>mini[i])
                        return 0;
                    if(v[i]<mini[i])
                        break;
                }
            }
            else
            {
                for(i=0;i<v.size();i++)
                {
                    if(v[i]>maxi[i])
                        return 0;
                    if(v[i]<maxi[i])
                        break;
                }
            }
        }
        
        x=0;
        for(i=0;i<v.size();i++)
            x = x + v[i]*pow(10,v.size()-i-1);
        
        return neg*x;    
    }
};