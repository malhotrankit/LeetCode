class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m,n,i,j,r=0,c=0;
        m= matrix.size();
        n= matrix[0].size();
        
        for(i=0;i<m;i++)
        {
            if(matrix[i][0]==0)
                c=1;
        }
        
        for(i=0;i<n;i++)
        {
            if(matrix[0][i]==0)
                r=1;
        }
        
        for(i=1;i<m;i++)
        {
            for(j=1;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        
        for(i=1;i<m;i++)
        {
            for(j=1;j<n;j++)
            {
                if(matrix[0][j]==0||matrix[i][0]==0)
                    matrix[i][j]=0;
            }
        }
        
        //if(matrix[0][0]==0)
        //{r=1;c=1;}
        
        if(r==1)
        {
            for(i=0;i<n;i++)
                matrix[0][i]=0;
        }
        if(c==1)
        {
            for(i=0;i<m;i++)
                matrix[i][0]=0;
        }
    }
};