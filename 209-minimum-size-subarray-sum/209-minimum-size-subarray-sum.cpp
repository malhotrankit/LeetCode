class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int i=0, n, len=0, sum=0, minLen = 100001;
        queue<int> q;
        n=nums.size();
        
        while(sum>=target||i<n)
        {
            if(target>sum)
            {
                sum += nums[i];
                q.push(nums[i]);
                len++;
                i++;
            }
            else
            {
                sum -= q.front();
                q.pop();
                if(minLen>len)
                    minLen = len;
                len--;
            }
            //printf("%d ",len);
        }
        
        if(minLen==100001)
            return 0;
        return minLen;
        
    }
};