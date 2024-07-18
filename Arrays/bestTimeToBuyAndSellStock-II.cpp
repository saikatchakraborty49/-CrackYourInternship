class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int bought=prices[0];
        for(auto i:prices){
            if(i-bought>=0){
                profit+=i-bought;
            }
            bought=i;
        }
        return profit;
    }
};