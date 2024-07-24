class Solution {
private:
    void solve(int n,int open,int close,vector<string>&ans,string& temp){
        if(open==n and close==n){
            ans.push_back(temp);
            return ;
        }
        if(open<n){
            temp.push_back('(');
            solve(n,open+1,close,ans,temp);
            temp.pop_back();
        }
        if(close<open){
            temp.push_back(')');
            solve(n,open,close+1,ans,temp);
            temp.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
        int close=0;
        int open=0;
        solve(n,open,close,ans,temp);
        return ans;
    }
};