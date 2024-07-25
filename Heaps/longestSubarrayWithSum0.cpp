//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        // unordered_map<int,vector<int>>mpp;
        // mpp[0].push_back(-1);
        // int sum=0;
        // for(int i=0;i<n;i++){
        //     sum+=arr[i];
        //     mpp[sum].push_back(i);
        // }
        // int ans=0;
        // for(auto i:mpp){
        //     auto list=i.second;
        //     ans=max(ans,list.back()-list[0]);
        // }
        // return ans;
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(mpp.find(sum)==mpp.end())
            mpp[sum]=i;
            else{
                ans=max(ans,i-mpp[sum]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends