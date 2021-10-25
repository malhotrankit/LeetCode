class Solution {
public:
    string intToRoman(int num) 
    {
    int arr[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string str[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        string s;
        int n, i, count,j;
        n = num;
        i = 12;
        while(n!=0)
        {
            count = n/arr[i];
            n = n % arr[i];
            for(j=0;j<count;j++)
                s.append(str[i]);
            i--;
        }
        return s;
    }
};