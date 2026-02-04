class Solution {
public:
    int minNumberOfFrogs(string s) {
            vector<int> greed(5, 0);
    int frogs = 0, maxi = 0;
    for(char c : s){
        if(c == 'c') {
            greed[0] ++;
            frogs++;
            maxi = max(frogs,maxi);
        }
        else if(c == 'r') {
            if(greed[0] == 0) return -1; 
            greed[0]--;
            greed[1]++;
        }
        else if(c == 'o') {
            if(greed[1] == 0) return -1; 
            greed[1]--;
            greed[2]++;           
        }
        else if(c == 'a') {
            if(greed[2] == 0) return -1; 
            greed[2]--;
            greed[3]++;
        }
        else if(c == 'k') {
            if(greed[3] == 0) return -1; 
            greed[3]--;
            frogs--;
        }
        else return -1;
    }
    return (frogs == 0) ?  maxi : -1;        
    }
};