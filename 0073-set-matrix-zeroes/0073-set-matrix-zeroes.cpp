class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // vector<pair<int,int>> temp;
        // for(int i=0;i<m;i++) {
        //     for(int j=0;j<n;j++) {
        //         if(matrix[i][j] == 0) {
        //             temp.push_back({i,j});
        //         }
        //     }
        // }

        // for(auto it : temp) {
        //     int pi = it.first;
        //     int pj = it.second;

        //     // col filling
        //     for(int i=0;i<m;i++) {
        //         matrix[i][pj] = 0;
        //     }
        //     //row filling
        //     for(int j=0;j<n;j++) {
        //         matrix[pi][j] = 0;
        //     }

        // }

        //optimal

        vector<int> row(m,0);
        vector<int> col(n,0);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};