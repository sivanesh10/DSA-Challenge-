class Solution {
private:
    vector<vector<int>>helper(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++) {
            if(ans.empty() || arr[i][0] > ans.back()[1]) {
                ans.push_back(arr[i]);
                continue;
            }
            else {
                if(arr[i][0] <= ans.back()[1]) {
                    ans.back()[1] = max(ans.back()[1],arr[i][1]);
                }
            }
        }
        return ans;
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        return helper(intervals);
    }
};