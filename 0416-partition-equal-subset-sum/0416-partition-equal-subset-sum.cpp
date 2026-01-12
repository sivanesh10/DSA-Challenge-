class Solution {
public:
    int f(int i,int tar,vector<int>& arr,vector<vector<int>> &dp) {
        if(tar == 0) return 1;
        if(i == 0) return arr[i] == tar;
        if(dp[i][tar] != -1) return dp[i][tar];
        bool notPick = f(i-1,tar,arr,dp);
        bool Pick = 0;
        if(arr[i] <= tar) Pick = f(i-1,tar - arr[i],arr,dp);
        return dp[i][tar] =  Pick | notPick;
    }
public:
    bool canPartition(vector<int>& arr) {
        int sum = 0;
        for(auto it : arr) sum += it;
        if (sum % 2 != 0) return false;
        int n = arr.size();
        int target = sum/2;
        // vector<vector<int>> dp(n,vector<int> (target+1,0));
        // return (bool) f(nums.size()-1,sum/2,nums,dp);
        
        // space optimisation
        vector<int> prev(target+1), cur(target+1,0);

        prev[0] = cur[0] = 1;
        if(arr[0] <= target) prev[arr[0]] = 1;
        for(int i = 1 ; i < n ; i++) {
            for(int k = 1 ; k <= target ; k++) {
                bool notPick = prev[k];
                bool Pick = 0;
                if(arr[i] <= k) Pick = prev[k - arr[i]];
                cur[k] =  Pick | notPick;
            }
            prev = cur;
        }
        return (bool) prev[target];
    }
};