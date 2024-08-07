//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int tab(string &s1, string &s2){
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
        int maxi=0;
        for(int i=s1.size()-1;i>=0;i--){
            for(int j=s2.size()-1;j>=0;j--){
                int ans=0;
                if(s1[i]==s2[j]){
                    ans=1+dp[i+1][j+1];
                    dp[i][j]=ans; 
                    maxi=max(ans,maxi);   
                }
                else{
                    dp[i][j]=0;
                    continue;
                }
            }  
        }
        return maxi;
    }
    int longestCommonSubstr(string s1, string s2) {
        // your code here
        return tab(s1,s2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends