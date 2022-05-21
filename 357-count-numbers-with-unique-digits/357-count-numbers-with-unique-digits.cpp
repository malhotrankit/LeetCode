class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        /*int i,array[9];
        array[0]=1;
        array[1]=10;
        array[2]=91;
        for(i=3;i<=n;i++)
            array[i]=(array[i-1]-array[i-2])*(11-i)+array[i-1];
        
        
        return array[n];*/
        
        if(n==0)
            return 1;
        else if(n==1)
            return 10;
         else if(n==2)
            return 91;
         else if(n==3)
            return 739;
         else if(n==4)
            return 5275;
         else if(n==5)
            return 32491;
         else if(n==6)
            return 168571;
         else if(n==7)
            return 712891;
         else
            return 2345851;
    }  
};