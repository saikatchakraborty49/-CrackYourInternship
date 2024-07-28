class Solution {
private:
    bool isPossible(int index,int i,vector<string>&a){
        int n=a.size();
        int row=index-1;
        int col=i-1;
        while(row>=0 and col>=0){
            if(a[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        row=index-1;
        col=i+1;
        while(row>=0 and col<n){
            if(a[row][col]=='Q'){
                return false;
            }
            row--;
            col++;
        }
        row=index-1;
        col=i;
        while(row>=0){
            if(a[row][col]=='Q'){
                return false;
            }
            row--;
        }
        return true;
    }
    void solve(int index,int n,vector<vector<string>>&ans,vector<string>&a){
        if(index==n){
            ans.push_back(a);
            return ;
        }
        for(int i=0;i<n;i++){
            if(isPossible(index,i,a)){
                a[index][i]='Q';
                solve(index+1,n,ans,a);
                a[index][i]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        string temp;
        for(int i=0;i<n;i++){
            temp.push_back('.');
        }
        vector<string>a;
        for(int i=0;i<n;i++){
            a.push_back(temp);
        }
        int index=0;
        vector<vector<string>>ans;
        solve(index,n,ans,a);
        return ans;
    }
};