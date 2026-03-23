class Solution {
public:
    pair<long,long> recursion(vector<vector<int>>& arr,int i, int j,int n,int m , vector<vector<pair<long,long>>>&dp) {
        //base
        if (i == n-1 && j == m-1) {
            return dp[i][j] = {arr[i][j], arr[i][j]};
        }
        long long l = LLONG_MIN;
        long long r = LLONG_MAX;
        //recurrence
        if(dp[i][j].first != -1 && dp[i][j].second != -1) return dp[i][j]; 
        if(j+1 < m) {
            auto apath = recursion(arr,i,j+1,n,m,dp);
            long long a = arr[i][j] * apath.first;
            long long b = arr[i][j] * apath.second;
            l = max({l,a,b});
            r = min({r,a,b});
        }
        if(i+1 < n) {
            auto bpath = recursion(arr,i+1,j,n,m,dp);
            long long a = arr[i][j] * bpath.first;
            long long b = arr[i][j] * bpath.second;
            l = max({l,a,b});
            r = min({r,a,b});
        }
        return dp[i][j] = {l,r};
    }
public: 
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<long,long>>> dp(m,vector<pair<long,long>>(n,{-1,-1}));
        auto ind = recursion(grid,0,0, m, n, dp);
        if (ind.first < 0) return -1;

        return ind.first % 1000000007;
    }
};