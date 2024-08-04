class Solution {
private:
    int noOfLiving(vector<vector<int>>& board,int i,int j){
        int m=board.size();
        int n=board[0].size();
        int lives=0;

        if(i+1<m and (board[i+1][j]==1 || board[i+1][j]==3)) lives++;
        if(i-1>=0 and (board[i-1][j]==1 || board[i-1][j]==3)) lives++;
        if(j+1<n and (board[i][j+1]==1 || board[i][j+1]==3)) lives++;
        if(j-1>=0 and (board[i][j-1]==1 || board[i][j-1]==3)) lives++;
        if(i-1>=0 and j-1>=0 and (board[i-1][j-1]==1 || board[i-1][j-1]==3)) lives++;
        if(i-1>=0 and j+1<n and (board[i-1][j+1]==1 || board[i-1][j+1]==3)) lives++;
        if(i+1<m and j-1>=0 and (board[i+1][j-1]==1 || board[i+1][j-1]==3)) lives++;
        if(i+1<m and j+1<n and (board[i+1][j+1]==1 || board[i+1][j+1]==3)) lives++;

        return lives;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==1){
                    if(noOfLiving(board,i,j)==2 || noOfLiving(board,i,j)==3){
                        board[i][j]=1;
                    }
                    else{
                        board[i][j]=3;
                    }
                }
                else if(board[i][j]==0){
                    if(noOfLiving(board,i,j)==3){
                        board[i][j]=2;
                    }
                    else{
                        board[i][j]=0;
                    }
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==2){
                    board[i][j]=1;
                }
                else if(board[i][j]==3){
                    board[i][j]=0;
                }
            }
        }
    }
};