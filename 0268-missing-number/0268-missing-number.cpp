class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int len = nums.size();
        // int formula = (len * (len+1)) / 2;
        // int x = 0;
        // for(auto it : nums) x += it;
        // return formula - x;
        int n = nums.size();
        int xr = 0;
        for(int i=0;i<n+1;i++)
            xr ^= i; 
        for(int i=0;i<n;i++)
           xr ^= nums[i];
        return xr;
    }
};