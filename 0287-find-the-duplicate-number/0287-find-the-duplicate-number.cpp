class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        // vector<int> mpp(n+1,0);
        // for(int i=0;i<n;i++) {
        //     mpp[nums[i]]++;
        //     if(mpp[nums[i]] > 1) return nums[i];
        // }
        // return -1;


        //optimal

        int s = nums[0],f = nums[0];

        s = nums[s];
        f = nums[nums[f]];
        while(s != f) {
            s = nums[s];
            f = nums[nums[f]];
        }
        s = nums[0];

        while(s != f) {
            s = nums[s];
            f = nums[f];
        }
        return s;
    }
};