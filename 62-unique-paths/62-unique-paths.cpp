class Solution 
{
    public:
    int uniquePaths(int m, int n) 
    {
        int matrix[101][101], i, j;
        for(i=1;i<=m;i++)
            matrix[i][1]=1;
        for(j=1;j<=n;j++)
            matrix[1][j]=1;
        for(i=2;i<=m;i++)
            for(j=2;j<=n;j++)
                matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
        return matrix[m][n];
        
    }
};