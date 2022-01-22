class Solution {
public:
    int climbStairs(int n) 
    {
        int a=1 , b=1 , c, i;
        for(i=2; i<n ; i++)
        {
            c = b;
            b = b+a;
            a = c;
            
        }
        if(n>1)
            return a+b;
        else
            return 1;
    }
};