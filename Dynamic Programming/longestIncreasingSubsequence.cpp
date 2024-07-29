class Solution {
private:
    int rec(int prev,int curr,vector<int>&nums){
        if(curr==nums.size()){
            return 0;
        }
        int include=0;
        if(prev==-1 or nums[prev]<nums[curr]){
            include=1+rec(curr,curr+1,nums);
        }
        int exclude=rec(prev,curr+1,nums);
        return max(include,exclude);
    }
    int mem(int prev,int curr,vector<int>&nums,vector<vector<int>>&dp){
        if(curr==nums.size()){
            return 0;
        }
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        int include=0;
        if(prev==-1 or nums[prev]<nums[curr]){
            include=1+mem(curr,curr+1,nums,dp);
        }
        int exclude=mem(prev,curr+1,nums,dp);
        return dp[curr][prev+1]=max(include,exclude);
    }
    int tab(vector<int>&nums){
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int include=0;
                if(prev==-1 or nums[prev]<nums[curr]){
                    include=1+dp[curr+1][curr+1];
                }
                int exclude=dp[curr+1][prev+1];
                dp[curr][prev+1]=max(include,exclude);
            }
        }
        return dp[0][0];
    }
    int SO(vector<int>&nums){
        int n=nums.size();
        vector<int>current(n+1,0);
        vector<int>previous(n+1,0);
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int include=0;
                if(prev==-1 or nums[prev]<nums[curr]){
                    include=1+previous[curr+1];
                }
                int exclude=previous[prev+1];
                current[prev+1]=max(include,exclude);
            }
            previous=current;
        }
        return previous[0];
    }
    int BS(vector<int>&nums){
        vector<int>temp;
        int n=nums.size();
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int lowerBound=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[lowerBound]=nums[i];
            }
        }
        return temp.size();
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int prev=-1;
        int curr=0;
        int n=nums.size();
        // return rec(prev,curr,nums);
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return mem(prev,curr,nums,dp);
        // return tab(nums);
        // return SO(nums);
        return BS(nums);
    }
};