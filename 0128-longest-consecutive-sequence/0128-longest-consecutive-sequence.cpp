class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mpp;
        for(int i=0;i<n;i++) {
            mpp[nums[i]] = i;
        } 
        int maxi = 0;
        for(auto [key,value] : mpp) {
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