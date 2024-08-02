class Solution {
private:
    int rec(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(row==grid.size()-1 and col==grid[0].size()-1) return grid[row][col];
        else if(row==grid.size() or col==grid[0].size()) return INT_MAX;
        
        if(dp[row][col]!=-1) return dp[row][col];
        
        int down=INT_MAX;
        int right=INT_MAX;
        
        int recAns=rec(row+1,col,grid,dp);
        if(recAns!=INT_MAX)
        down=grid[row][col]+recAns;
        
        recAns=rec(row,col+1,grid,dp);
        if(recAns!=INT_MAX)
        right=grid[row][col]+recAns;
                
        return dp[row][col]=min(down,right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans=rec(0,0,grid,dp);
        return ans;
    }
};