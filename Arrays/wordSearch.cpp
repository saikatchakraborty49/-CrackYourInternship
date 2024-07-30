class Solution {
private:
    bool solve(int index,int row,int col,vector<vector<char>>& board, string word,vector<vector<bool>>&visited){
        if(row<0 or row>=board.size() or col<0 or col>=board[0].size() or word[index]!=board[row][col] or index>=word.size() or visited[row][col]==true) return false;
        if(index==word.size()-1) return true;
        visited[row][col]=true;
        //down
        bool ans1=solve(index+1,row+1,col,board,word,visited);
        //up
        bool ans2=solve(index+1,row-1,col,board,word,visited);
        //right
        bool ans3=solve(index+1,row,col+1,board,word,visited);
        //left
        bool ans4=solve(index+1,row,col-1,board,word,visited);
        visited[row][col]=false;
        return ans1 or ans2 or ans3 or ans4;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false));
                    if(solve(0,i,j,board,word,visited)){ 
                    // cout<<i<<" "<<j<<endl;
                    return true;}
            }
        }
        return false;
    }
};