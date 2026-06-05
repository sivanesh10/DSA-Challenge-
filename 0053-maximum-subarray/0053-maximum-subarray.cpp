class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxi = INT_MIN;
        int start = 0;
        int end;

        for(int i=0;i<n;i++) {
            sum += nums[i];
            
            if(sum > maxi) {
                maxi = sum;
                end = i;
            }

            if(sum < 0) { sum = 0; start = i+1;} 
        }
        for(int it = start;it <= end;it++) cout << nums[it] << "  ";
        return maxi;
    }
};