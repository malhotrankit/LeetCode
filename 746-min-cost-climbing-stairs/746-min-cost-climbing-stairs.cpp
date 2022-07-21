class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n ,i;
        n = cost.size();
        for(i=2; i<n; i++)
        {
            if(cost[i-1]>cost[i-2])
                cost[i]+=cost[i-2];
            else
                cost[i]+=cost[i-1];
        }
        /*for(int i=0; i<n; i++)
            printf("%d ",cost[i]);
        printf("\n");*/
        if(cost[n-1]<cost[n-2])
            return cost[n-1];
        else
            return cost[n-2];
    }
};