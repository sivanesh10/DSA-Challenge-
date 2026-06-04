class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // finding pivot
        int n = nums.size();
        int pivot = -1;
        for(int i=n-1;i>0;i--) {
            if(nums[i-1] < nums[i]) {
                pivot = i-1;
                break;
            }
        }
        cout<< pivot;
        if(pivot != -1){
            for(int i = n - 1; i > pivot; i--) {
                if(nums[i] > nums[pivot]) {
                    swap(nums[i], nums[pivot]);
                    break;
                }
            }
        }
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};