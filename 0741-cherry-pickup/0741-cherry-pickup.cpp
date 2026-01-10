class Solution {
public:
    int f(int r1,int c1,int r2,vector<vector<int>> &arr,int n) {
        // Forcing the Person 2 (Coloumn 2) to move the same (step or time) that the person 1 moves;
        // maatrix theory row 1 + col 1 = row 2 + col 2 == which equals to step or time ..k
        //rearrange to get c2 -----> c2 = (r1 + c1) - r2
        
        int c2 = (r1 + c1) - r2;
        
        // Invalid thrones or Boundary overflow ...

        if (r1 < 0 || c1 < 0 || r2 < 0 || c2 < 0 || arr[r1][c1] == -1 || arr[r2][c2] == -1)
            return -1e9;


        //Base Hit
        
        if(r1 == 0 && r2 == 0 && c1 == 0 && c2 == 0) {
            return arr[0][0];
        }

        
        // picking ups cherry at that cell r,c;

        //two cases is that 
        // 1 -> on same cell pick any one 
        // 2 -> different cell pick two cherries;

        int cherries = arr[r1][c1];
        if(r1 != r2 || c1 != c2) cherries += arr[r2][c2];


        // next 4 ways to go 

        // UP _ UP
        // UP _ LEFT
        // LEFT _ UP
        // LEFT _ LEFT

        int best = max({
            f(r1-1, c1,   r2-1, arr,n), // down, down
            f(r1,   c1-1, r2,   arr,n), // right, right
            f(r1-1, c1,   r2,   arr,n), // down, right
            f(r1,   c1-1, r2-1, arr,n)  // right, down
        }); 

        // return max cheries path of those 4 ways

        return cherries + best; 

    }


    int memo(int r1,int c1,int r2,vector<vector<int>> &arr,int n,vector<vector<vector<int>>>& dp) {

        // Forcing the Person 2 (Coloumn 2) to move the same (step or time) that the person 1 moves;
        // maatrix theory row 1 + col 1 = row 2 + col 2 == which equals to step or time ..k
        //rearrange to get c2 -----> c2 = (r1 + c1) - r2
        
        int c2 = (r1 + c1) - r2;
        
        // Invalid thrones or Boundary overflow ...

        if (r1 < 0 || c1 < 0 || r2 < 0 || c2 < 0 || arr[r1][c1] == -1 || arr[r2][c2] == -1)
            return -1e9;


        //Base Hit
        
        if(r1 == 0 && r2 == 0 && c1 == 0 && c2 == 0) {
            return arr[0][0];
        }

        if(dp[r1][c1][r2] != -1) return dp[r1][c1][r2];
        // picking ups cherry at that cell r,c;

        //two cases is that 
        // 1 -> on same cell pick any one 
        // 2 -> different cell pick two cherries;

        int cherries = arr[r1][c1];
        if(r1 != r2 || c1 != c2) cherries += arr[r2][c2];


        // next 4 ways to go 

        // UP _ UP
        // UP _ LEFT
        // LEFT _ UP
        // LEFT _ LEFT

        int best = max({
            memo(r1-1, c1,   r2-1, arr,n,dp), // down, down
            memo(r1,   c1-1, r2,   arr,n,dp), // right, right
            memo(r1-1, c1,   r2,   arr,n,dp), // down, right
            memo(r1,   c1-1, r2-1, arr,n,dp)  // right, down
        }); 

        // return max cheries path of those 4 ways

        return dp[r1][c1][r2] = cherries + best; 

    }


    // Tabulations..
    int tabu(vector<vector<int>>& arr,int n,vector<vector<vector<int>>> &dp) {
        dp[0][0][0] = arr[0][0];
        
        if (arr[0][0] == -1) return 0;
        for(int r1=0;r1<n;r1++) {
            for(int c1=0;c1<n;c1++) {
                for (int r2=0;r2<n;r2++) {
                    
                    int c2 = (r1 + c1) - r2;
                    if (c2 < 0 || c2 >= n) continue;

                    if (arr[r1][c1] == -1 || arr[r2][c2] == -1)
                        continue;

                    if (r1 == 0 && r2 == 0 && c1 == 0) continue;
                    
                    int dd = -1e9,rr = -1e9,dr = -1e9,rd = -1e9;
                    
                    if(r1 > 0 && r2 > 0) dd = dp[r1-1][c1][r2-1]; // down, down
                    if(c1 > 0) rr = dp[r1][c1-1][r2]; // right, right
                    if(r1 > 0) dr = dp[r1-1][c1][r2]; // down, right
                    if(c1 > 0 && r2 > 0) rd = dp[r1][c1-1][r2-1]; // right, down
                    
                    int best = max({dd,rr,rd,dr});
                    if(best == -1e9) continue;
                    
                    int cherries = arr[r1][c1];
                    if(r1 != r2 || c1 != c2) cherries += arr[r2][c2];

                    dp[r1][c1][r2] = cherries + best;
                }
            }
        }
        return dp[n-1][n-1][n-1];
    }

// space optimization
        int so(vector<vector<int>>& grid) {
            int n = grid.size();
            const int NEG = -1e9;

            // prev[r1][r2] = dp at previous step
            // curr[r1][r2] = dp at current step
            vector<vector<int>> prev(n, vector<int>(n, NEG));
            vector<vector<int>> curr(n, vector<int>(n, NEG));

            // Base case
            if (grid[0][0] == -1) return 0;
            prev[0][0] = grid[0][0];

            // step = r + c
            for (int step = 1; step <= 2 * (n - 1); step++) {
                // reset current layer
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        curr[i][j] = NEG;

                for (int r1 = 0; r1 < n; r1++) {
                    int c1 = step - r1;
                    if (c1 < 0 || c1 >= n) continue;

                    for (int r2 = 0; r2 < n; r2++) {
                        int c2 = step - r2;
                        if (c2 < 0 || c2 >= n) continue;

                        if (grid[r1][c1] == -1 || grid[r2][c2] == -1)
                            continue;

                        int best = NEG;
                        best = max(best, prev[r1][r2]);                 // R, R
                        if (r1 > 0) best = max(best, prev[r1-1][r2]);   // D, R
                        if (r2 > 0) best = max(best, prev[r1][r2-1]);   // R, D
                        if (r1 > 0 && r2 > 0)
                            best = max(best, prev[r1-1][r2-1]);         // D, D

                        if (best == NEG) continue;

                        int cherries = grid[r1][c1];
                        if (r1 != r2 || c1 != c2)
                            cherries += grid[r2][c2];

                        curr[r1][r2] = best + cherries;
                    }
                }
                prev = curr;
            }
            return prev[n-1][n-1];
}

public:
    int cherryPickup(vector<vector<int>>& grid) {
     
     int n = grid.size();

    //  return f(n-1,n-1,n-1,grid,n); 

    //memo..
    // vector<vector<vector<int>>> dp(n,vector<vector<int>> (n,vector<int> (n,-1)));
    // return max(0,memo(n-1,n-1,n-1,grid,n,dp));

    //tabu..
    // vector<vector<vector<int>>> dp(n,vector<vector<int>> (n,vector<int> (n,-1e9)));
    // return max(0,tabu(grid,n,dp));

    //space optimization
    vector<vector<int>> prev(n,vector<int> (n,-1e9)),curr(n,vector<int> (n,-1e9));
    return max(0,so(grid));
    }
};