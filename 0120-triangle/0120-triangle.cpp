class Solution {
private:
    //Recurrence ...
    int r(vector<vector<int>>& triangle,int i,int j,int n,vector<vector<int>>& dp) {
        if(i == n-1) return triangle[n-1][j];
        if(dp[i][j] != -1) return dp[i][j];
        int d = triangle[i][j] + r(triangle,i+1,j,n,dp);
        int dg = triangle[i][j] + r(triangle,i+1,j+1,n,dp);
        return dp[i][j] = min(d,dg);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        //Tabulation ...

        // vector<vector<int>> dp (n,vector<int>(n,-1));
        // return r(triangle,0,0,n,dp);

        //Space Optimized ...
        vector<int> prev(n,0),curr(n,0);
        for(int i=0;i<n;i++) {
            prev[i] = triangle[n-1][i]; 
        }
        for(int i=n-2;i>=0;i--) {
            for(int j=0;j<=i;j++) {
                int d = prev[j] + triangle[i][j];
                int dg = prev[j+1] + triangle[i][j];
                curr[j] = min(d,dg);
            }
            prev = curr;
        }
        return prev[0];
    }
};