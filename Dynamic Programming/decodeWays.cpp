class Solution {
private:
    int solve(int index,string &s,vector<int>&dp){
        if(index==s.size()) return 1;
        else if(index>s.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int ans1=0;
        int ans2=0;
        int oneDigit=(s[index]-'0');
        if(oneDigit==0) 
            ans1=0;
        else 
            ans1=solve(index+1,s,dp);
        if(index+1!=s.size()){
            int twoDigit=(s[index]-'0')*10+(s[index+1]-'0');
            if(twoDigit>=10 and twoDigit<=26) 
                ans2=solve(index+2,s,dp);
            else 
                ans2=0;
        }
        return dp[index]=ans1+ans2;
    }
public:
    int numDecodings(string s) {
        int index=0;
        vector<int>dp(s.size()+1,-1);
        return solve(index,s,dp);
    }
};