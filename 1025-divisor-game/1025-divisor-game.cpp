class Solution {
private:
    bool rec(int n,vector<int> &dp) {
        if(n==1) return false;
        if(dp[n] != -1) return dp[n];
        for (int i=1;i*i<=n;i++) {
            if(n%i == 0) {
                if((n-1) < n && !rec(n-i,dp)) return dp[n] = true;
                if(i!=1 && (n-(n/i)) < n && !rec(n-(n/i),dp)) return dp[n] = true;
            }
        }
        return dp[n] = false;
    }
public:
    bool divisorGame(int n) {
        
        //by math (Game Theory)....
        // return n%2 == 0;

        vector<int> dp(n+1,-1);
        return rec(n,dp);
    }
};