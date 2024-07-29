//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    long long rec(int i,int size,int n){
        if(size==n){
            return 1;
        }
        
        long long ans=0;
        long long curr=rec(i,size+1,n);
        ans+=curr;
        
        long long up=0;
        if(i==0){ 
            up=rec(8,size+1,n);
            // ans+=up;
            // return ans;
        }
        else if(i<=3) up=0;
        else up=rec(i-3,size+1,n);
        ans+=up;
        
        long long left=0;
        if(i==0 or i==1 or i==4 or i==7) left=0;
        else left=rec(i-1,size+1,n);
        ans+=left;
        
        long long right=0;
        if(i==0 or i==3 or i==6 or i==9) right=0;
        else right=rec(i+1,size+1,n);
        ans+=right;
        
        long long down=0;
        if(i==8) down=rec(0,size+1,n);
        else if(i==0 or i==7 or i==9) down=0;
        else down=rec(i+3,size+1,n);
        ans+=down;
        
        return ans;
    }
    long long mem(int i,int size,int n,vector<vector<long long>>&dp){
        if(size==n){
            return 1;
        }
        if(dp[size][i]!=-1) return dp[size][i];
        
        long long ans=0;
        long long curr=mem(i,size+1,n,dp);
        ans+=curr;
        
        long long up=0;
        if(i==0){ 
            up=mem(8,size+1,n,dp);
            // ans+=up;
            // return ans;
        }
        else if(i<=3) up=0;
        else up=mem(i-3,size+1,n,dp);
        ans+=up;
        
        long long left=0;
        if(i==0 or i==1 or i==4 or i==7) left=0;
        else left=mem(i-1,size+1,n,dp);
        ans+=left;
        
        long long right=0;
        if(i==0 or i==3 or i==6 or i==9) right=0;
        else right=mem(i+1,size+1,n,dp);
        ans+=right;
        
        long long down=0;
        if(i==8) down=mem(0,size+1,n,dp);
        else if(i==0 or i==7 or i==9) down=0;
        else down=mem(i+3,size+1,n,dp);
        ans+=down;
        
        return dp[size][i]=ans;
    }
    long long tab(int n){
        vector<vector<long long>>dp(n+1,vector<long long>(10,1));

        for(int i=n-1;i>=1;i--){
            for(int j=0;j<=9;j++){
                long long ans=0;
                long long curr=dp[i+1][j];
                ans+=curr;
                
                long long up=0;
                if(j==0){ 
                    up=dp[i+1][8];
                }
                else if(j<=3) up=0;
                else up=dp[i+1][j-3];
                ans+=up;
                
                long long left=0;
                if(j==0 or j==1 or j==4 or j==7) left=0;
                else left=dp[i+1][j-1];
                ans+=left;
                
                long long right=0;
                if(j==0 or j==3 or j==6 or j==9) right=0;
                else right=dp[i+1][j+1];
                ans+=right;
                
                long long down=0;
                if(j==8) down=dp[i+1][0];
                else if(j==0 or j==7 or j==9) down=0;
                else down=dp[i+1][j+3];
                ans+=down;

                dp[i][j]=ans;
            }
            
        }
        long long ans=0;
        for(int i=0;i<=9;i++)
        ans+=dp[1][i];
        return ans;
    }
  public:
    long long getCount(int n) {
        // Your code goes here
        // if(n==1) return 10;
        long long ans=0;
        // for(int i=0;i<=9;i++){
            // ans+=rec(i,1,n);
            // vector<vector<long long>>dp(n+1,vector<long long>(10,-1));
            // ans+=mem(i,1,n,dp);
        // }
        ans=tab(n);
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

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends