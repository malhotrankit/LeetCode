class Solution 
{
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        int i=0, pos1, pos2, n, maximum=INT_MIN, count=0, pos;
        vector<pair<int,int>> v;
        n= nums.size();
        pos1= n;
        
        for(;i<n;)
        {
            if(count==0||(count>0&&v[count-1].second<=nums[i]))
            {
                v.push_back(make_pair(i,nums[i]));
                i++;
                count++;
            }
            else
            {
                if(pos1>v[count-1].first)
                {
                    pos1= v[count-1].first;
                }
                if(maximum<v[count-1].second)
                {
                    maximum=v[count-1].second;
                    pos2= v[count-1].first;
                }
                v.pop_back();
                count--;
            }
        }
        //cout<<maximum;
        //cout<<count;
        //cout<<pos1<<" "<<pos2;
        if(count==n)
        {
            //cout<<"a";
            return 0;
        }
        while(count!=0)
        {
            if(maximum>v[count-1].second)
            {
                pos=v[count-1].first;
                break;
            }
            count--;
        }
        return pos-pos1+1;
    }
};