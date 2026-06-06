// Brute approach of extra space not inplace

// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();

//         vector<vector<int>> temp(n, vector<int>(n));

//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < n; j++) {
//                 temp[j][n - 1 - i] = matrix[i][j];
//             }
//         }

//         matrix = temp;
//     }
// };


// Optimal Transpose + Reverse row
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Transpose
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};