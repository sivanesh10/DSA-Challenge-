class Solution {
public:
    long long f(int i,int j,vector<vector<int>>& arr,int n,int m,vector<vector<long long>> &dp) {
        if(j<0 || j>=m) return 1e18;
        if(i == 0) return arr[0][j];
        if(dp[i][j] != -1) return dp[i][j];
        long long u = arr[i][j] + f(i-1,j,arr,n,m,dp);
        long long ld = arr[i][j] + f(i-1,j-1,arr,n,m,dp);
        long long rd = arr[i][j] + f(i-1,j+1,arr,n,m,dp);
        return dp[i][j] = min(u,min(ld,rd));
    }
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        long long ans = 1e9;
        // vector<vector<long long>> dp (n,vector<long long> (m,0));/
        // for(int j=0;j<=m-1;j++) {
        //     dp[0][j] = arr[0][j];
        // }

        //Tabulation ...

        // for(int i = 1; i < n; i++) {
        //     for(int j = 0; j < m; j++) {
        //         long long u, ld = 1e9, rd = 1e9;
        //         u = arr[i][j] + dp[i-1][j];
        //         if(j > 0) ld = arr[i][j] + dp[i-1][j-1];
        //         if(j < m-1) rd = arr[i][j] + dp[i-1][j+1];
        //         dp[i][j] = min (u,min(ld,rd));
        //     }
        // }

        // for(int i=0;i<m;i++) {
        //     ans = min(ans,dp[n-1][i]);
        // }


        // Space Optimization .. 

        vector<long long> curr(m,0), prev(m,0);

        for(int j=0;j<=m-1;j++) {
            prev[j] = arr[0][j];
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                long long u, ld = 1e9, rd = 1e9;
                u = arr[i][j] + prev[j];
                if(j > 0) ld = arr[i][j] + prev[j-1];
                if(j < m-1) rd = arr[i][j] + prev[j+1];
                curr[j] = min (u,min(ld,rd));
            }
            prev = curr;
        }

        for(int i=0;i<m;i++) {

            //fetching minimum among the m-1 starts answer from last row computation 
            ans = min(ans,prev[i]);
        }

        


        return (int) ans;
    }
};