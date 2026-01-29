class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int prev = -1, curr = arr[n-1], maxi = 0;
        arr[n-1] = -1;
        for(int i=n-2;i>=0;i--) {
            maxi = max(curr,maxi);
            prev = curr;
            curr = arr[i];
            arr[i] = maxi;
        }
        for(auto it : arr) cout << it << " ";
        return arr;
    }
};