class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int i, j ,k, l , p, n, m;
        n= matrix.size();
        m= matrix[0].size();
        vector<int> v;
    
        if(n%2==1)
        {
            for(i=0;i<n/2+1;i++)
            {
                for(j=i;j<m-i&&i<=n/2;j++)
                    v.push_back(matrix[i][j]);
            
                for(k=i+1;k<n-i&&m-i-1>=m/2;k++)
                    v.push_back(matrix[k][m-i-1]);
            
                for(l=m-i-2;l>=i&&n-i-1>n/2;l--)
                    v.push_back(matrix[n-i-1][l]);
                
                for(p=n-i-2;p>=i+1&&i<m/2;p--)
                    v.push_back(matrix[p][i]);
            }
        }
        
        else
        {
            for(i=0;i<n/2;i++)
            {
               for(j=i;j<m-i&&i<n/2;j++)
                    v.push_back(matrix[i][j]);
            
                for(k=i+1;k<n-i&&m-i-1>=m/2;k++)
                    v.push_back(matrix[k][m-i-1]);
            
                for(l=m-i-2;l>=i&&n-i-1>=n/2;l--)
                    v.push_back(matrix[n-i-1][l]);
                
                for(p=n-i-2;p>=i+1&&i<m/2;p--)
                    v.push_back(matrix[p][i]);
            }
        }
        return v;
    }
};