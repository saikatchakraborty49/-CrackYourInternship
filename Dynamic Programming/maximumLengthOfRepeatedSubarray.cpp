class Solution {
private:
    int rec(int n1,int n2,vector<int>& nums1, vector<int>& nums2,vector<vector<int>>&dp){
        if(n1==nums1.size() || n2==nums2.size()) return 0;
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        int ans=0;
        if(nums1[n1]!=nums2[n2]){
            rec(n1+1,n2,nums1,nums2,dp);
            rec(n1,n2+1,nums1,nums2,dp);
            rec(n1+1,n2+1,nums1,nums2,dp);
            return dp[n1][n2]=0;
        }
        else{
            return 1+rec(n1+1,n2+1,nums1,nums2,dp);
        }
    }
    int tab(vector<int>& nums1, vector<int>& nums2){
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        int maxi=0;
        for(int i=nums1.size()-1;i>=0;i--){
            for(int j=nums2.size()-1;j>=0;j--){
                int ans=0;
                if(nums1[i]==nums2[j]){
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
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // int n1=0;
        // int n2=0;
        // vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,-1));
        // int maxi=0;
        // for(int i=0;i<nums1.size();i++){
        //     for(int j=0;j<nums2.size();j++){
        //         maxi=max(maxi,rec(i,j,nums1,nums2,dp));
        //     }
        // }
        // return maxi;
        return tab(nums1,nums2);
    }
};