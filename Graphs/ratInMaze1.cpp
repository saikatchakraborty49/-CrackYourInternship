//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void solve(int row,int col,vector<vector<int>> &mat,vector<string>&ans,string &temp,vector<vector<bool>>&vis){
        if(row==mat.size()-1 and col==mat[0].size()-1){
            ans.push_back(temp);
            return ;
        }
        vector<pair<int,int>>moves{{1,0},{-1,0},{0,1},{0,-1}};
        for(auto i:moves){
            int tempRow=row+i.first;
            int tempCol=col+i.second;
            if(tempRow>=0 and tempRow<mat.size() and tempCol>=0 and tempCol<mat[0].size() and mat[tempRow][tempCol]==1 and vis[tempRow][tempCol]==false){
                vis[tempRow][tempCol]=true;
                if(i==make_pair(0,1)){
                    temp.push_back('R');
                }
                else if(i==make_pair(0,-1)){
                    temp.push_back('L');
                }
                else if(i==make_pair(1,0)){
                    temp.push_back('D');
                }
                else if(i==make_pair(-1,0)){
                    temp.push_back('U');
                }
                solve(tempRow,tempCol,mat,ans,temp,vis);
                temp.pop_back();
                vis[tempRow][tempCol]=false;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        if(mat[0][0]==0) return {"-1"};
        vector<string>ans;
        string temp;
        int row=0;
        int col=0;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vis[row][col]=true;
        solve(row,col,mat,ans,temp,vis);
        if(ans.size()==0)return {"-1"};
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends