class Solution 
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int sum = 0, i, cur = 0, pos = 0;
        
        for(i=0;i<cost.size();i++)
        {
            sum += gas[i] - cost[i];
            cur += gas[i] - cost[i];
            if(cur < 0)
            {
                pos = i + 1;
                cur = 0;
            }
        }
        if(sum >= 0)
            if(pos==cost.size())
                return 0;
            else
                return pos;
        else
            return -1;
        
    }
};