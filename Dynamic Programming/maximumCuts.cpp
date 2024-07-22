//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    private:
    int rec(int n,int x,int y,int z,bool &found){
        if(n==0){
            found=true;
            return 0;
        };
        if(n<0) return INT_MIN;
        
        int ans1=1+rec(n-x,x,y,z,found);
        int ans2=1+rec(n-y,x,y,z,found);
        int ans3=1+rec(n-z,x,y,z,found);
        return max(ans1,max(ans2,ans3));
    }
    int mem(int n,int x,int y,int z,vector<int>&dp,bool &found){
        if(n==0){
            found=true;
            return 0;
        };
        if(n<0) return INT_MIN;
        
        if(dp[n]!=-1) return dp[n];
        
        int ans1=1+mem(n-x,x,y,z,dp,found);
        int ans2=1+mem(n-y,x,y,z,dp,found);
        int ans3=1+mem(n-z,x,y,z,dp,found);
        
        return dp[n]=max(ans1,max(ans2,ans3));
    }
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here 
        // return rec(n,x,y,z);
        vector<int>dp(n+1,-1);
        bool found=false;
        int ans=mem(n,x,y,z,dp,found);
        if(found) return ans;
        else return 0;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends