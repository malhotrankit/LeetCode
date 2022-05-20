class Solution 
{
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n,i,j,max=1;
        n=nums.size();
        vector<int> positive(n,1);
        vector<int> negative(n,1);
        if(n<=1)
        {
            if(n==0)
                return 0;
            else
                return 1;
        }
        for(i=1;i<n;i++)
        {
            for(j=i-1;j>=0;j--)
            {
                if(nums[i]-nums[j]>0&&positive[i]<negative[j]+1)
                {
                    positive[i]=negative[j]+1;
                    if(max<positive[i])
                        max=positive[i];
                }
                if(nums[i]-nums[j]<0&&negative[i]<positive[j]+1)
                {
                        negative[i]=positive[j]+1;
                        if(max<negative[i])
                            max=negative[i];
                }
            }
            
        }
        return  max;
    }
};