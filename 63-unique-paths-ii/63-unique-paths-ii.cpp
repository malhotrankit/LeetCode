class Solution 
{
    public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int n, m, i, j;
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        vector<vector<int>> vec( m+1 , vector<int> (n+1, 0));
        
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
                if(obstacleGrid[i-1][j-1]==1)
                    vec[i][j] = -1;
        
        for(i=1;i<=m;i++)
            if(vec[i][1]==-1)
                break;
            else
                vec[i][1]=1;
        
        for(j=1;j<=n;j++)
            if(vec[1][j]==-1)
                break;
            else
                vec[1][j]=1;
        
        for(i=2;i<=m;i++)
        {
            for(j=2;j<=n;j++)
            {
                if(vec[i][j]!=-1&&vec[i-1][j]==-1&&vec[i][j-1]!=-1)
                    vec[i][j] = vec[i][j-1];
                else if(vec[i][j]!=-1&&vec[i-1][j]!=-1&&vec[i][j-1]==-1)
                    vec[i][j]=vec[i-1][j];
                else if(vec[i][j]!=-1&&vec[i-1][j]!=-1&&vec[i][j-1]!=-1)
                    vec[i][j]=vec[i-1][j]+vec[i][j-1];
                else
                    vec[i][j]=-1;
            }
        }
        
        if(vec[m][n]==-1)
            return 0;
        else
            return vec[m][n];
    }
};