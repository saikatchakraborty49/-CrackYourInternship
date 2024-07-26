class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int l=0;l<nums.size();l++){
            if(l!=0 and nums[l]==nums[l-1]) continue;
            for(int k=l+1;k<nums.size();k++){
                if(k!=l+1 and nums[k]==nums[k-1]) continue;
                int i=k+1;
                int j=nums.size()-1;
                while(i<j){
                    //REMEMBER TO CHECK IF SUM IS EXCEEDING INT LIMITS
                    long long sum=(long long)(nums[i])+(long long)(nums[j])+(long long)(nums[k])+(long long)(nums[l]);
                    if(sum==target) {ans.push_back({nums[l],nums[k],nums[i],nums[j]}); 
                        i++; j--;
                        while(i<nums.size() and nums[i]==nums[i-1]) i++;
                        while(j>k and nums[j]==nums[j+1]) j--;
                        
                    }
                    else if(sum>target) j--;
                    else i++;
                }
            }
        }
        return ans;
    }
};