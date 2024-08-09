class Solution {
bool checkWalk(vector<vector<int>>& grid,vector<vector<bool>>& vis){
    int n=grid.size();
    int m=grid[0].size();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0 and vis[i][j]==false){
                return false;
            }
        }
    }
    return true;
}
int solve(int row,int col,vector<vector<int>>& grid,vector<vector<bool>>& vis){
    if(grid[row][col]==2 and checkWalk(grid,vis)) return 1;
    if(grid[row][col]==2) return 0;
    int ans1=0;
    int ans2=0;
    int ans3=0;
    int ans4=0;
    int n=grid.size();
    int m=grid[0].size();
    if(row+1<n and grid[row+1][col]!=-1 and grid[row+1][col]!=1 and vis[row+1][col]==false){
        vis[row+1][col]=true;
        ans1=solve(row+1,col,grid,vis);
        vis[row+1][col]=false;
    }
    if(row-1>=0 and grid[row-1][col]!=-1 and grid[row-1][col]!=1 and vis[row-1][col]==false){
        vis[row-1][col]=true;
        ans2=solve(row-1,col,grid,vis);
        vis[row-1][col]=false;
    }
    if(col+1<m and grid[row][col+1]!=-1 and grid[row][col+1]!=1 and vis[row][col+1]==false){
        vis[row][col+1]=true;
        ans3=solve(row,col+1,grid,vis);
        vis[row][col+1]=false;
    }
    if(col-1>=0 and grid[row][col-1]!=-1 and grid[row][col-1]!=1 and vis[row][col-1]==false){
        vis[row][col-1]=true;
        ans4=solve(row,col-1,grid,vis);
        vis[row][col-1]=false;
    }
    return ans1+ans2+ans3+ans4;
}
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int row=0;
        int col=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    row=i;
                    col=j;
                }
            }
        }
        return solve(row,col,grid,vis);
    }
};