class Solution 
{
public:
    int countSubstrings(string s) 
    {
        int i, j, count=0, n;
        n = s.length();
        vector<vector<int>> grid(n, vector<int>(n, 0));
        
        for(i=0;i<n;i++)
            grid[i][i]=1;
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(s[i]==s[j]&&i-j+1==grid[i-1][j+1]+2)
                {
                    grid[i][j]= grid[i-1][j+1]+2;
                    count++;
                }
            }
        }
        
        return count+n;
    }
};