class Solution 
{
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        int i,max,n;
        max = *max_element(nums.begin(), nums.end());
        vector<int> v(10001,0),array(10001,0);//,sum<10001,0>;
        n=nums.size();
        for(i=0;i<n;i++)
            v[nums[i]]++;
        array[1]=v[1];
        array[2]=2*v[2];
        for(i=3;i<=max;i++)
        {
            if(i*v[i]+array[i-2]>i*v[i]+array[i-3])
            {
                array[i]=i*v[i]+array[i-2];
            }
            else
            {
                 array[i]=i*v[i]+array[i-3];
            }
        }
        return *max_element(array.begin(), array.end());
    }
};