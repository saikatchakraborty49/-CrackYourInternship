class Solution {
private:
    int rec(map<pair<int,int>,int>&mpp,vector<int>& arr,int start,int end,vector<vector<int>>&dp){
        if(start==end) return 0;
        if(start>end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int mini=INT_MAX;
        for(int i=start;i<end;i++){
            mini=min(mini,mpp[{start,i}]*mpp[{i+1,end}]+rec(mpp,arr,start,i,dp)+rec(mpp,arr,i+1,end,dp));
        }
        return dp[start][end]=mini;
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int>mpp;
        for(int i=0;i<arr.size();i++){
            int maxi=0;
            for(int j=i;j<arr.size();j++){
                mpp[{i,j}]=max(maxi,arr[j]);
                maxi=max(maxi,arr[j]);
            }
        }
        vector<vector<int>>dp(arr.size()+1,vector<int>(arr.size()+1,-1));
        int start=0;
        int end=arr.size()-1;
        return rec(mpp,arr,start,end,dp);
    }
};