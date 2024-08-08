//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    bool rec(int index,int sum,int arr[],int n,vector<vector<int>>&dp){
        if(sum==0) return true;
        if(sum<0 or index==n) return false;
        if(dp[sum][index]!=-1) return dp[sum][index];
        bool ans1=rec(index+1,sum-arr[index],arr,n,dp);
        bool ans2=rec(index+1,sum,arr,n,dp);
        return dp[sum][index]=(ans1 or ans2);
    }
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        vector<vector<int>>dp(sum/2+1,vector<int>(N+1,-1));
        int index=0;
        if(sum%2==1) return false;
        sum/=2;
        return rec(index,sum,arr,N,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends