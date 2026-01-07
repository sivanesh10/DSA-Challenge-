class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> prev;
        for (int i=0;i<numRows;i++) {
            vector<int> curr(i+1,1);
            for(int j=1;j<i;j++) {
                // if (j == 0 || j == i) curr[j] = 1;
                curr[j] = prev[j-1] + prev[j];
            }
            res.push_back(curr);
            prev = curr;
        }
        return res;
    }
};