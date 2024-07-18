class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currProfit=0;
        int maximumProfit=0;
        int bought=prices[0];
        for(int i=0;i<prices.size();i++){
            currProfit=prices[i]-bought;
            if(currProfit<0){
                currProfit=0;
                bought=prices[i];
            }
            maximumProfit=max(maximumProfit,currProfit);
        }
        return maximumProfit;
    }
};