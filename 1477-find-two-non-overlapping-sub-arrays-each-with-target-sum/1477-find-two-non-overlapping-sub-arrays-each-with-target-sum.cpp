class Solution {
public:
       
    int minSumOfLengths(vector<int>& arr, int target) 
    {
        int i, minimum=INT_MAX, ans=INT_MAX, sum=0, n;
        unordered_map<int,int> ht;
        n=arr.size();
        sum=arr[0];
        ht.insert(make_pair(0,-1));
        ht.insert(make_pair(sum,0));
        for(i=1;i<n;i++)
        {
            sum=sum+arr[i];
            ht.insert(make_pair(sum,i));
        }
       
        sum=0;
        for(i=0;i<n;i++)
        {
            sum=sum+arr[i];
            //ans=INT_MAX;
            if(ht.find(sum-target)!=ht.end())
                ans = min(ans,i-ht[sum-target]);
            if(ht.find(sum+target)!=ht.end()&&ans!=INT_MAX)
                minimum = min(minimum,ans+ht[sum+target]-i);
        }
        if(minimum==INT_MAX)
            return -1;
        return minimum;
    }
};