//User function Template for C++

class Solution {
  public:
    bool isPalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int index,string s,vector<vector<string>>& ans,vector<string>&temp){
        if(index==s.size()){
            ans.push_back(temp);
            return ;
        }
        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                solve(i+1,s,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        int index=0;
        vector<vector<string>>ans;
        vector<string>temp;
        solve(index,S,ans,temp);
        return ans;
    }
};