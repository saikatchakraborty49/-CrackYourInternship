class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        int i;
        int j;
        for(int k=0;k<n;k++){
            i=k+1;
            j=n-1;
            if (k!=0 && nums[k] == nums[k-1]) continue;
            
            while(i<j){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum==0){ 
                ans.push_back({nums[i],nums[j],nums[k]});
                j--;
                i++;
                while(i<j and nums[j]==nums[j+1]) j--;
                while(i<j and nums[i]==nums[i-1]) i++;
            }
            else if(sum>0) j--;
            else i++;
        }
        }
        return ans;
    }
};