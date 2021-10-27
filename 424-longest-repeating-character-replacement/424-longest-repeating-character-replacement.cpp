class Solution 
{
public:
    int characterReplacement(string s, int k) 
    {
        int i, len, l , r, ans=0, maxi;
        int arr[26];
        for(i=0;i<26;i++)
            arr[i]=0;
        len = s.length();
        l=r=0;
        while(r<len&&l<=r)
        {
            maxi=0;
            arr[s[r]-65]++;
            for(i=0;i<26;i++)
            {
                if(maxi<arr[i])
                    maxi = arr[i];
            }
            if(r-l+1-maxi<=k)
            {
                if(r-l+1>ans)
                    ans = r-l+1;
                r++;
            }
            else
            {
                arr[s[l]-65]--;
                l++;
                r++;
            }
        }
        
        return ans;
    }
};