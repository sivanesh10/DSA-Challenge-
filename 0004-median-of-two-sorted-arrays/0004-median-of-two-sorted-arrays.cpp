class Solution {
public: 
    double brute(vector<int>& nums1, vector<int>& nums2,int n,int m) {
        vector<int> arr(n+m);
        for(int i=0;i<n;i++) {
            arr[i] = nums1[i];
        }
        int id = 0;
        for(int j=n;j<n+m;j++) {
            arr[j] = nums2[id];
            id++;
        }
        sort(arr.begin(),arr.end());
        if((m+n)%2 != 0) {
            return arr[(m+n-1)/2];
        }
        else {
            int idx = (n+m-1)/2;
            double nu = (arr[idx] + arr[idx+1]) / 2.0;
            return nu;
        }
        return -1;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        return brute(nums1,nums2,n,m);
    }
};