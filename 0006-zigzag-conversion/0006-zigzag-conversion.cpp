class Solution {
private:
    string zigzag(string s,int n) {
        vector<string> vec(n,"");
        int i = 0;
        int t = 0;
        int d = 1;
        // int cnt = 0;
        while (i < s.size()) {
            vec[t] += s[i];
            if((t == 0 && i != 0) || t == n-1) {
                if(d == 1) d = -1;
                else d = 1;
            }
            t = t + d;
            i++;
        }
        string ans;
        for(auto i : vec) {
            ans += i;
        }
        return ans;
    }
public:
    string convert(string s, int numRows) {
        return zigzag(s,numRows);
    }
};