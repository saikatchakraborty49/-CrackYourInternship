class Solution {
public:
    int rec(vector<int>&coins,long long sum,int amount,bool &ansAvailable){
        if(sum==amount) {
            ansAvailable=true;
            return 0;
        }
        int mini=INT_MAX-1;
        for(int i=0;i<coins.size();i++){
            if(sum+coins[i]<=amount){
                sum+=coins[i];
                mini=min(mini,1+rec(coins,sum,amount,ansAvailable));
                sum-=coins[i];
            }
        }        
        return mini;
    }
    int mem(vector<int>&coins,long long sum,int amount,bool &ansAvailable,vector<int>&dp){
        if(sum==amount) {
            ansAvailable=true;
            dp[sum]=0;
        }
        if(dp[sum]!=-1) return dp[sum];
        int mini=INT_MAX-1;
        for(int i=0;i<coins.size();i++){
            if(sum+coins[i]<=amount){
                sum+=coins[i];
                mini=min(mini,1+mem(coins,sum,amount,ansAvailable,dp));
                sum-=coins[i];
            }
        }        
        return dp[sum]=mini;
    }
    int tab(vector<int>&coins,int amount,vector<int>&dp){
        dp[amount]=0;
        for(long long sum=amount-1;sum>=0;sum--){
        int mini=INT_MAX;
            for(int i=0;i<coins.size();i++){
                if(sum+coins[i]<=amount){
                    if(dp[sum+coins[i]]!=INT_MAX)
                    mini=min(mini,1+dp[sum+coins[i]]);
                }
            }
            dp[sum]=mini;
        }
        return dp[0];
    }
    int coinChange(vector<int>& coins, int amount) {
        long long sum=0;
        bool ansAvailable=false;
        // int ans=rec(coins,sum,amount,ansAvailable);
        vector<int>dp(amount+1,INT_MAX);
        int ans=tab(coins,amount,dp);
        // return ans;
        if(ans!=INT_MAX) return ans;
        else return -1;
    }
};