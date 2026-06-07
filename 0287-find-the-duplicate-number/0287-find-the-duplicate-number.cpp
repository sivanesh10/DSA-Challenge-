class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> mpp(n+1,0);
        for(int i=0;i<n;i++) {
            mpp[nums[i]]++;
            if(mpp[nums[i]] > 1) return nums[i];
        }
        return -1;
    }
};