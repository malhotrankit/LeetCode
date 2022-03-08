class Solution 
{
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n,i=0,area,maxArea=0,top=-1;
        n = heights.size();
        int stack[n+1];
        heights.push_back(-1);
        
        while(top!=-1||i!=n)
        {
            if(top==-1||heights[stack[top]]<=heights[i])
            {
                ++top;
                stack[top]= i;
                if(i<n)
                    ++i;
            }
            else
            {
                if(top==0)
                    area = heights[stack[top]] * i;
                else
                    area = heights[stack[top]] * (i-stack[top-1]-1);
                if(area>maxArea)
                    maxArea= area;
                --top;
            }
        }
        
        return maxArea;
    }
};