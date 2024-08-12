class Solution {
public:
    bool isSafe(int row,int col,vector<vector<int>>& image,int oldColor){
        int n=image.size();
        int m=image[0].size();
        if(row>=0 and row<n and col>=0 and col<m and image[row][col]==oldColor){
            return true;
        }
        else return false;
    }
    void dfs(int parentRow,int parentCol,int row,int col,int color,int oldColor,vector<vector<int>>& image){
        image[row][col]=color;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int newRow=row+dx[i];
            int newCol=col+dy[i];
            if(newRow==parentRow and newCol==parentCol) continue;
            if(isSafe(newRow,newCol,image,oldColor)){                
                dfs(row,col,newRow,newCol,color,oldColor,image);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int oldColor=image[sr][sc];
        if(oldColor==color) return image;
        dfs(sr,sc,sr,sc,color,oldColor,image);
        return image;
    }
};