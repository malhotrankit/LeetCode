class KthLargest 
{
public:
    int arr[20001];
    int K;
    int N;
    
    KthLargest(int k, vector<int>& nums) 
    {
        int i,n;
        K=k;
        n= nums.size();
        N=n;
        for(i=0;i<20001;i++)
            arr[i]=0;
        for(i=0;i<n;i++)
            arr[nums[i]+10000]++;
    }
    
    inline int add(int val) 
    {
        int i,ele;
        arr[val+10000]++;
        ele= K;
        
        for(i=20000;i>=0;i--)
        {
            ele= ele-arr[i];
            if(ele<=0)
                break;
        }
        
        return i-10000;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */