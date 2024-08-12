class Solution {
public:
     bool isSafe(int row,int col,vector<vector<bool>>& vis,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(row>=0 and row<n and col>=0 and col<m and vis[row][col]==false and grid[row][col]=='1'){
            return true;
        }
        else return false;
    }
    void dfs(int row,int col,vector<vector<bool>>& vis,vector<vector<char>>& grid){
        vis[row][col]=true;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int newRow=row+dx[i];
            int newCol=col+dy[i];
            if(isSafe(newRow,newCol,vis,grid)){                
                dfs(newRow,newCol,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==false and grid[i][j]=='1'){
                    dfs(i,j,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};