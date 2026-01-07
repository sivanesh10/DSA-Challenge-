class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        int slen = s.size();
        for (auto it : t) {
            if(s[idx] == it){
                idx++;
                continue;
            }
        }
        return (idx == slen);
    }
};