class Solution {
public:
    int r(int i,int j1,int j2,vector<vector<int>>& arr,int n,int m,vector<vector<vector<int>>> &dp) {
        
        //out of bound
        if(j1 < 0 || j2 < 0 || j1 > m-1 || j2 > m-1) {
            return -1e9;
        } 
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        //Base condition
        if(i == n-1) {
            if(j1 == j2) {
                return arr[i][j1]; 
            }
            return arr[i][j1] + arr[i][j2];
        }


        int maxi = -1e9;
        for(auto dj1 : {-1,0,+1}) {
            for(auto dj2 : {-1,0,+1}) {
                int cherry = 0;
                if (j1 != j2) cherry = arr[i][j1] + arr[i][j2];
                else cherry = arr[i][j1];
                cherry += r(i+1,j1+dj1,j2+dj2,arr,n,m,dp);
                maxi =  max(maxi,cherry);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int>(m,-1)));
        return r(0,0,m-1,grid,n,m,dp);
    }
};