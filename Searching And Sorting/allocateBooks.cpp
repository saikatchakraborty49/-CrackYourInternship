//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  private:
    bool isPossible(int n,int arr[],int m,long long pages){
        int mCnt=1;
        long long pageCnt=0;
        for(int i=0;i<n;i++){
            if(pageCnt+arr[i]<=pages){
                pageCnt+=arr[i];
            }
            else{
                mCnt++;
                pageCnt=arr[i];
            }
        }
        if(mCnt<=m)
        return true;
        else return false;
    }
  public:
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        if(m>n) return -1;
        // code here
        long long sum=0;
        long long maxi=0;
        for(int i=0;i<n;i++) {
            sum+=arr[i];
            maxi=arr[i]>maxi?arr[i]:maxi;
        }
        long long s=maxi;
        long long e=sum;
        long long mid=s+(e-s)/2;
        long long ans=-1;
        while(s<=e){
            if(isPossible(n,arr,m,mid)) {
                e=mid-1;
                ans=mid;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
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
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends