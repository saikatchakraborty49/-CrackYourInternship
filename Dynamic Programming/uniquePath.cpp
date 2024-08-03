class Solution {
private:
    int rec(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i==m-1 and j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        //down
        if(i+1<=m-1){
            ans+=rec(i+1,j,m,n,dp);
        }
        //right
        if(j+1<=n-1){
            ans+=rec(i,j+1,m,n,dp);
        }
        return dp[i][j]=ans;
    }
public:
    int uniquePaths(int m, int n) {
        int i=0;
        int j=0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return rec(i,j,m,n,dp);
    }
};