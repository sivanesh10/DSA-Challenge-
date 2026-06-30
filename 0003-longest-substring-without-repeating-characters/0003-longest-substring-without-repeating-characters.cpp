class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        set<char>  st;
        int maxi = 0;
        for(int right = 0;right < n; right++) {
            while(st.count(s[right])) {
                st.erase(s[left++]);
            }
            st.insert(s[right]);
            maxi = max(maxi,right-left+1);
        }
        return maxi;
    }
};