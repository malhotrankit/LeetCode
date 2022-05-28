class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) 
    {
        int n, m, i, j, count=0, minimum;
        m = matrix.size();
        n = matrix[0].size();
       
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i-1>=0&&j-1>=0&&matrix[i][j]>0)
                {
                    minimum = min(matrix[i-1][j],matrix[i][j-1]);
                    minimum = min(minimum,matrix[i-1][j-1]);
                    matrix[i][j]= matrix[i][j] + minimum;
                }
            }
        }
        
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                count= count+ matrix[i][j];
            }
        }
     return count;   
    }
};