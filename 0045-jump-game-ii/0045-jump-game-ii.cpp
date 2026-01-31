class Solution {
private: 
    int f(int i,vector<int>& arr,int n, vector<int>& dp) {
        if(i == n-1) return 0;
        if(arr[i] == 0) return 1e9;
        if(dp[i] != -1) return dp[i];
        int take = 1e9;
        for(int j = 1; j <= arr[i] ; j++) {
            if(i+j <= n-1) take = min(1 + f(i+j,arr,n,dp),take);
        }
        return dp[i] = take;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[n-1] = 0;
        for (int i = n-2; i >= 0; i--) {
            int take = 1e9;
            if(nums[i] == 0) dp[i] = 1e9;
            for(int j = 1; j <= nums[i]; j++) {
                if(i+j <= n-1) take = min(1 + dp[i+j],take);
            }
            dp[i] = take;
        }
        return dp[0];
    }
};