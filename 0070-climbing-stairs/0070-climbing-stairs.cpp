class Solution {
// private:
//     int f(int n,vector<int> &dp){
//         if(n == 0) return 1;
//         else if (n < 0) return 0;
//         else if (dp[n] != -1) return dp[n];
//         else{
//             return dp[n] = f(n-1,dp) + f(n-2,dp);
//         }
//     }
public:
    int climbStairs(int n) {
        int prev = 0; 
        int prev2 = 1;
        int curr = 0;
        if(n >= 1) prev = 1;
        for (int i=2;i<=n;i++) {
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;

        }
        // return f(n,dp);
        return prev;
    }
};