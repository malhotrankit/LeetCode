class Solution {
public:
    int countVowelStrings(int n) 
    {
        int array[5];
        array[0]=array[1]=array[2]=array[3]=array[4]=1;
        for(int i=2;i<=n;i++)
        {
            array[0]=array[0]+array[1]+array[2]+array[3]+array[4];
            array[1]=array[1]+array[2]+array[3]+array[4];
            array[2]=array[2]+array[3]+array[4];
            array[3]=array[3]+array[4];
        }
        return (array[0]+array[1]+array[2]+array[3]+array[4]);
    }
   
};