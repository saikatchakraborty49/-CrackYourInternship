class Solution {
private:
    bool rec(int index,vector<int>&nums,vector<int>&dp){
        if(index>=nums.size()-1){
            return true;
        }
        if(dp[index]!=-1) return dp[index];
        bool ans=false;
        for(int i=1;i<=nums[index];i++){
            if(index+i==nums.size()-1) return dp[index]=true;
            if(index+i<nums.size() and nums[i+index]!=0)
            ans=rec(index+i,nums,dp);
            if(ans==true) return dp[index]=true;
        }
        return dp[index]=false;
    }
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return rec(0,nums,dp);
    }
};