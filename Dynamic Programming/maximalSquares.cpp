class Solution {
private:
    int rec(int i,int j,vector<vector<char>>& matrix,int &maxi,vector<vector<int>>&dp){
        if(i>=matrix.size() or j>=matrix[0].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=rec(i,j+1,matrix,maxi,dp);
        int bottom=rec(i+1,j,matrix,maxi,dp);
        int diagonal=rec(i+1,j+1,matrix,maxi,dp);
        if(matrix[i][j]=='1'){
            int ans=1+min(right,min(diagonal,bottom));
            maxi=max(ans,maxi);
            return dp[i][j]=ans;
        }
        else return dp[i][j]=0;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int i=0;
        int j=0;
        int maxi=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        rec(i,j,matrix,maxi,dp);
        return maxi*maxi;
    }
};