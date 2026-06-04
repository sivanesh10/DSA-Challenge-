class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> degree(n);

        for(int i=0;i<n;i++) {
            for(int j=0;j<=i;j++) {
                if(matrix[i][j] == 1) {
                    degree[i]++;
                    degree[j]++;
                }
            }
        }
        return degree;
    }
};