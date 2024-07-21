class Solution {
public:
    int solveByRec(int steps,int n){
        if(steps==n) return 0;
        if(steps==n-1) return 1;
        if(steps==n-2) return 2;
        return solveByRec(steps+1,n)+solveByRec(steps+2,n);
    }
    int memoization(vector<int>&dp,int steps,int n){
        if(steps==n) return 0;
        if(steps==n-1) return 1;
        if(steps==n-2) return 2;

        if(dp[steps]!=-1) return dp[steps];
        
        return dp[steps]=memoization(dp,steps+1,n)+memoization(dp,steps+2,n);
    }
    int tab(int n){
        vector<int>dp(n+1,-1);
        dp[n]=0;
        dp[n-1]=1;
        if(n>1)
        dp[n-2]=2;

        for(int steps=n-3;steps>=0;steps--){
            dp[steps]=dp[steps+1]+dp[steps+2];
        }
        return dp[0];
    }
    int spaceOpt(int n){
        if(n==1) return 1;
        if(n==2) return 2;
        int prev=1;
        int curr=2;
        int ans;
        for(int steps=n-3;steps>=0;steps--){
            ans=prev+curr;
            prev=curr;
            curr=ans;
        }
        return ans;
    }
    int climbStairs(int n) {
        int steps=0;
        vector<int>dp(n+1,-1);
        // return solveByRec(steps,n);
        // return memoization(dp,steps,n);
        // return tab(n);
        return spaceOpt(n);
    }
};