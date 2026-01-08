class Solution {
public:
    int f (int n,vector <int> &dp) {
        if (n<=1) return n;
        else if (n==2) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = f (n-1,dp) + f (n-2,dp) + f (n-3,dp);
    }
public:
    int tribonacci(int n) {
        // vector <int> dp(n+1,-1);
        // return f (n,dp);



        //Tabulation
        // if(n <= 1) return n;
        // if(n == 2) return 1;
        // dp[0] = 0;
        // dp[1] = 1;
        // dp[2] = 1;
        // for(int i=3;i<=n;i++) {
        //     dp[i] = dp [i-1] + dp [i-2] + dp [i-3];
        // }
        // return dp [n];



        // Space Optimization ..

        if(n <= 1) return n;
        if(n == 2) return 1;
        int curri,prev,prev2,prev3;
        prev3 = 0;
        prev2 = 1;
        prev = 1;
        for(int i=3;i<=n;i++) {
            curri = prev + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};