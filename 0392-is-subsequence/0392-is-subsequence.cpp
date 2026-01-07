class Solution {
private:
    bool rec(string s,string t, int l, int r, vector<vector<int>> &dp,int n,int m) {
        if (l == n) return true;
        if (r == m) return false;
        if(dp[l][r] != -1) return dp[l][r];
        if (s[l] == t[r]) return dp[l][r] = rec(s,t,l+1,r+1,dp,n,m);
        return dp[l][r] =  rec(s,t,l,r+1,dp,n,m);
    }
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return rec(s,t,0,0,dp,n,m);
        // int idx = 0;
        // int slen = s.size();
        // for (auto it : t) {
        //     if(s[idx] == it){
        //         idx++;
        //         continue;
        //     }
        // }
        // return (idx == slen);
    }
};