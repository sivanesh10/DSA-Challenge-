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
    ///optimal tc -> O(m * n)  sc -> O(2n)
    int tabu(int m, int n,vector<int>& prev,vector<int>& curr) {
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i == 0 && j == 0) curr[j] = 1;
                else {
                    int above = 0;
                    int left = 0;
                    if(i > 0) above = prev[j];
                    if(j > 0) left = curr[j-1];
                    curr[j] = above + left;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m,vector<int> (n,0));
        vector<int> prev(n,0);
        vector<int> curr(n,0); 
        // return dfs(m-1,n-1,m,n,dp);
        return tabu(m,n,prev,curr);
    }
};