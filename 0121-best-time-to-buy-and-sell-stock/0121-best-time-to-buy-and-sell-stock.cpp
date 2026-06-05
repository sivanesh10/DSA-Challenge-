class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Profit=0;
        int Minimum = prices[0];
        for(int i = 0 ; i<prices.size();i++){
            Minimum = min(Minimum,prices[i]);
            Profit = max(Profit,prices[i]-Minimum); 
        }return Profit;
    }
};