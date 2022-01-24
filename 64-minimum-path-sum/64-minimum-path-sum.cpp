class Solution 
{
public:
    int minPathSum(vector<vector<int>>& matrix) 
    {
        int m, n , i, j;
        m= matrix.size();
        n= matrix[0].size();
        //m= grid.size();
        //n= grid[0].size();
        //int matrix [m][n];
        
        /*for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                matrix[i][j]= grid[i][j];
        }*/
        
        for(i=1;i<n;i++)
        {
            matrix[0][i]+= matrix[0][i-1];
        }
        
        for(i=1;i<m;i++)
        {
            matrix[i][0]+= matrix[i-1][0];
        }
        
        for(i=1;i<m;i++)
        {
            for(j=1;j<n;j++)
            {
                if(matrix[i-1][j]<matrix[i][j-1])
                    matrix[i][j]+= matrix[i-1][j];
                else
                    matrix[i][j]+= matrix[i][j-1];
            }
        }
        return matrix[m-1][n-1];
    }
};