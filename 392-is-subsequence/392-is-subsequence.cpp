class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int len1, len2, pos, i, j, count=0;
        len1 = s.length();
        len2 = t.length();
        pos=0;
        for(i=0; i<len1; i++)
        {
            for(j=pos; j<len2; j++)
            {
                if(s[i]==t[j])
                {
                    count++;
                    pos=j+1;
                    break;
                }
            }
        }
        if(count== len1)
            return true;
        else
            return false;
    }
};