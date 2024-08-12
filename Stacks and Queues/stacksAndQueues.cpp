class Solution {
public:
    bool isSafe(int row,int col,vector<vector<bool>>& vis,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(row>=0 and row<n and col>=0 and col<m and vis[row][col]==false and grid[row][col]==1) return true;
        else return false;
    }
    int bfs(vector<vector<int>>& grid,vector<vector<bool>>& vis,queue<pair<pair<int,int>,int>>&q){
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        int ans=0;
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int row=top.first.first;
            int col=top.first.second;
            int time=top.second;
            for(int i=0;i<4;i++){
                int newRow=row+dx[i];
                int newCol=col+dy[i];
                if(isSafe(newRow,newCol,vis,grid)){
                    vis[newRow][newCol]=true;
                    grid[newRow][newCol]=2;
                    q.push({{newRow,newCol},time+1});
                    ans=time+1;
                }
            }
        }
        return ans;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }
        int ans=bfs(grid,vis,q);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return ans;
    }
};