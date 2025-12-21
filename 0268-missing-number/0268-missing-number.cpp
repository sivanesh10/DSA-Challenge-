class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int formula = (len * (len+1)) / 2;
        int x = 0;
        for(auto it : nums) x += it;
        return formula - x;
    }
};