class Solution {
public:
    int dfs(int i, int j,int m, int n,vector<vector<int>>& dp) {
        if(i == 0 && j == 0) {
            return 1;
        }
        int l = 0;
        int r = 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(j-1 >= 0)
            l = dfs(i,j-1,m,n,dp);//right
        if(i-1 >= 0)
            r = dfs(i-1,j,m,n,dp);//down
        return dp[i][j] = l + r;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return dfs(m-1,n-1,m,n,dp);
    }
};