class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int k) {
        int l = 0;
        int m = arr.size();
        int n = arr[0].size();
        int h = (m * n) - 1;

    
        while(l <= h) {
            int mid = l + ((h-l) / 2);
            int row = (int) mid / n;
            int col = mid % n;
            if(arr[row][col] == k) {
                return true;
            }
            else if(arr[row][col] < k) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
        return false;
    }
};