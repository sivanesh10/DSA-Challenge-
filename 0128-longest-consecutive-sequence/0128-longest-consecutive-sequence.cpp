class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mpp(nums.begin(), nums.end());
        int maxi = 0;
        for(auto key : mpp) {
            if(mpp.find(key - 1) == mpp.end()) {
                int cnt = 1;
                int curr = key;
                while(mpp.find(curr + 1) != mpp.end()) {
                    cnt++;
                    curr++;
                }
                maxi = max(maxi,cnt);
            }
        }
        return maxi;
    }
};