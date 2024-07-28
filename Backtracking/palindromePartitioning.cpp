class Solution {
private:
    bool isPalindrome(int s,int e,string &str){
        while(s<e){
            if(str[s]!=str[e]) return false;
            s++; e--;
        }
        return true;
    }
    void solve(int index,vector<string>&temp,string s,vector<vector<string>>&ans){
        if(index==s.size()){
            ans.push_back(temp);
            return ;
        }
        for(int i=index;i<s.size();i++){
            if(isPalindrome(index,i,s)){
                temp.push_back(s.substr(index,i-index+1));
                solve(i+1,temp,s,ans);
                temp.pop_back();
            }
        }

    }
public:
    vector<vector<string>> partition(string s) {
        int index=0;
        vector<string>temp;
        vector<vector<string>>ans;
        solve(index,temp,s,ans);
        return ans;
    }
};