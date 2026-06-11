class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans1 = 0;
        int cnt1 = 0;
        int ans2 = 0;
        int cnt2 = 0;
        vector<int> vec;
        int threshold = n/3;

        for(int i=0;i<n;i++) {
            if(cnt1 == 0 &&  nums[i] != ans2) {
                ans1 = nums[i];
                cnt1++;
            }
            else if(cnt2 == 0 && nums[i] != ans1) {
                ans2 = nums[i];
                cnt2++;
            }
            else if(ans1 == nums[i]) {
                cnt1++;
            } 
            else if(ans2 == nums[i]) {
                cnt2++;
            } 
            else {
                cnt1--,cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;

        for(int num : nums) {
            if(num == ans1) cnt1++;
            else if(num == ans2) cnt2++;
        }
        
        if(cnt1 > threshold) {
            vec.push_back(ans1);
        }
        if(cnt2 > threshold) {
            vec.push_back(ans2);
        }
        return vec;
    }
};