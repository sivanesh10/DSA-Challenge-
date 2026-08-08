class Solution {
public: 
    int firstOcc (vector<int>& a,int k, int n){
        int low = 0;
        int high = n-1;
        int first = -1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(a[mid] == k) {
                first = mid;
                high = mid - 1; 
            } 
            else if (a[mid] > k) {
                high = mid - 1;
            }
            else 
                low = mid + 1;
            cout << "first = " << first << endl; 
        }
        return first;
    }
public: 
    int lastOcc (vector<int>& a,int k, int n){
        int low = 0;
        int high = n-1;
        int last = -1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(a[mid] == k) {
                last = mid;
                low = mid + 1;
            } 
            else if (a[mid] > k) {
                high = mid - 1;
            }
            else 
                low = mid + 1;
            cout << "last = "<< last << endl; 
        }
        return last;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int firstEle = firstOcc(nums,target,n);
        if(firstEle == -1) return {-1,-1};
        int lastEle = lastOcc(nums,target,n);
        return  {firstEle, lastEle};
    }
};