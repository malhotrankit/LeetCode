class Solution 
{
public:
    inline void rotate(vector<vector<int>>& matrix) 
    {
        int i, j, n, ele1, ele2, k, l;
        n=matrix[0].size();
      
        for(i=0; i<n/2; i++)
        {
            for(j=i; j<n-i-1; j++)
            {
                ele1= matrix[j][n-i-1];
                matrix[j][n-i-1]= matrix[i][j];
                ele2= matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j]= ele1;
                ele1= ele2;
                ele2= matrix[n-1-j][i];
                matrix[n-1-j][i]= ele1;
                ele1= ele2;
                matrix[i][j] = ele1;
            }
        }
    }
};