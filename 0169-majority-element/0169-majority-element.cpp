class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int cnt = 0;

        for(int i=0;i<n;i++) {
            if(cnt == 0) {
                ans = nums[i];
                cnt++;
            }
            else if(ans == nums[i]) {
                cnt++;
            } 
            else {
                cnt--;
            }
        }
        return ans;
    }
};