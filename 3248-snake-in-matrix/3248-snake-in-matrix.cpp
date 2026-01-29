class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int istep = 0;
        int jstep = 0;
        for(auto it : commands){
            if(it == "RIGHT"){
                ++jstep;
            }
            else if(it == "LEFT"){
                --jstep;
            }
            else if(it == "UP"){
                --istep;
            }
            else
            {
                ++istep;
            }
        }
        return (istep*n) + jstep;
    }
};