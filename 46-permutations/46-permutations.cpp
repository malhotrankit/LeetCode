class Solution 
{
public:
    vector<vector<int>> matrix;
    vector<int> v;
    
    inline void swap(int left, int right)
    {
        int ele;
        ele = v[left];
        v[left]= v[right];
        v[right]=ele;
    }
    
    inline void permutation(int left, int right)
    {
        if(left==right)
        {
            matrix.push_back(v);    
        }
        
        else
        {
            for(int i=left; i<=right;i++)
            {
                swap(left,i);
                permutation(left+1, right);
                swap(left,i);
            }
            
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        int i,n;
        n= nums.size();
        for(i=0; i<n; i++)
            v.push_back(nums[i]);
        permutation(0,n-1);
        return matrix;
    }
};