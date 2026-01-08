class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Greedy ..
        int maxi  = 0;
        for (int i=0;i<nums.size();i++) {
            if (maxi < i) return false;
            maxi = max (maxi, i + nums[i]);
        }
        return true;
    
    }
};