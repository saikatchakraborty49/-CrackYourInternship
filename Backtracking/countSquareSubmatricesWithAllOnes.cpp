class Solution {
public:
    int rec(int i,int j,vector<vector<int>>& matrix,int &cnt,vector<vector<int>>&dp,vector<vector<bool>>&vis){
        if(i>=matrix.size() or j>=matrix[0].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=rec(i,j+1,matrix,cnt,dp,vis);
        int bottom=rec(i+1,j,matrix,cnt,dp,vis);
        int diagonal=rec(i+1,j+1,matrix,cnt,dp,vis);
        if(matrix[i][j]==1){
            int ans=1+min(right,min(diagonal,bottom));
            if(vis[i][j]==false){
                cnt+=ans;
                vis[i][j]=true;
            }
            return dp[i][j]=ans;
        }
        else return dp[i][j]=0;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int i=0;
        int j=0;
        int cnt=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        vector<vector<bool>>vis(n+1,vector<bool>(m+1,false));
        rec(i,j,matrix,cnt,dp,vis);
        return cnt;
    }
};