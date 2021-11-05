class Solution {
public:

int numDecodings(string s) {
    int i, dp[101], len;
    len = s.length();
    dp[0]= 1;
    dp[1]= 1;
    if(s[0]=='0'||len==0)
        return 0;
    for(i=2;i<len+1;i++)
    {
        if(s[i-1]=='0'&&s[i-2]=='0')
            return 0;
        if(s[i-1]=='0')
        {
            if(s[i-2]>'2')
                return 0;
            dp[i]= dp[i-2];
            continue;
        }
        if(s[i-2]=='0')
        {
            dp[i]= dp[i-1];
            continue;
        }
        if(s[i-2]=='1'||(s[i-2]<='2'&&s[i-1]<='6'))
                dp[i]= dp [i-1] + dp[i-2];
        else
            dp[i]= dp[i-1];
    }
    /*for(i=0;i<len+1;i++)
        printf("%d ",dp[i]);*/
        
    return dp[len];
}
};