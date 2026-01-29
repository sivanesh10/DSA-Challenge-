class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        vector<vector<int>> grid(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grid[i][j] = (i*n) + j;
            }
        }
        int cur = grid[0][0];
        int istep = 0;
        int jstep = 0;
        for(auto it : commands){
            if(it == "RIGHT"){
                cur = grid[istep][++jstep];
            }
            else if(it == "LEFT"){
                cur = grid[istep][--jstep];
            }
            else if(it == "UP"){
                cur = grid[--istep][jstep];
            }
            else
            {
                cur = grid[++istep][jstep];
            }
        }
        return cur;
    }
};