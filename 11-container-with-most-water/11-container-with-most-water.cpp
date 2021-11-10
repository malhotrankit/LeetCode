class Solution 
{
public:
    inline int maxArea(vector<int>& height) 
    {
        int maxi=0,i,j;
        i = 0;
        j = height.size()-1;
        
        while(i<j)
        {
            maxi = max(maxi, (j-i) * min(height[i], height[j]));
            
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        
        return maxi;
    }
};