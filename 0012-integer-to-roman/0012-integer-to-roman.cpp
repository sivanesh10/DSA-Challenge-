class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>> mpp = {
            {1 ,"I"},
            {4 , "IV"},
            {5 , "V"},
            {9 , "IX"},
            {10 , "X"},
            {40 , "XL"},
            {50 , "L"},
            {90 , "XC"},
            {100 , "C"},
            {400 , "CD"},
            {500 , "D"},
            {900 , "CM"},
            {1000 , "M"}
        };
        string ans = "";
        for(int i = 12;i>=0;i--) {
            if(num <= 0) break;
            int q = num / mpp[i].first;
            while(q) {
                ans += mpp[i].second;
                q--;
            }
            num %= mpp[i].first;
            
        } 
        return ans;
    }
};