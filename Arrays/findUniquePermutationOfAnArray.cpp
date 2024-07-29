//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    void solve(vector<vector<int>>&ans,vector<int>&temp,vector<bool>&visited,vector<int>&arr){
        if(temp.size()==arr.size()){
            ans.push_back(temp);
            return ;
        }
        for(int i=0;i<arr.size();i++){
            if(i-1>=0 and visited[i-1]==false and arr[i]==arr[i-1]) continue;
            if(visited[i]==true) continue;
            temp.push_back(arr[i]);
            visited[i]=true;
            
            solve(ans,temp,visited,arr);
            
            visited[i]=false;
            temp.pop_back();
        }
    }
    public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>visited(n,false);
        solve(ans,temp,visited,arr);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends