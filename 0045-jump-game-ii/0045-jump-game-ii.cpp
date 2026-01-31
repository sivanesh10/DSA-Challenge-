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
        vector<int> dp(n,-1);
        return f(0,nums,n,dp);
    }
};