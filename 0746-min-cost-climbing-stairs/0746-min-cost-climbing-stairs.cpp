class Solution {
public:
    int r(vector<int>& cost,int idx,vector<int> &dp) {
        if (idx <= 1) return 0;
        if(dp[idx] != -1) return dp[idx];
        int step1 = INT_MAX,step2 = INT_MAX;    
        step1 = cost[idx-1] + r(cost,idx-1,dp);
        step2 = cost[idx-2] + r(cost,idx-2,dp);
        return dp[idx] = min(step1,step2);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = 0;
        int prev = 0;
        int curr;
        int step1 = 0, step2 = 0;
        for (int idx=2;idx<=n;idx++) {
            curr = min(cost[idx-1] + prev, cost[idx-2] + prev2);
            prev2 = prev;
            prev = curr;
        }
        return prev;
        //return r (cost,n,dp);
    }
};