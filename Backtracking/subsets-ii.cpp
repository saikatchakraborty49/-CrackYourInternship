class Solution {
public:
    void f(int index,vector<int>&temp,vector<vector<int>>&ans,vector<int>&nums){
        if(index==nums.size()){
            ans.push_back(temp);
            return ;
        }
        //include
        temp.push_back(nums[index]);
        index++;
        f(index,temp,ans,nums);

        //backtrack
        temp.pop_back();

        //exclude
        while(index<nums.size() and nums[index]==nums[index-1])index++;
        f(index,temp,ans,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        int index=0;
        f(index,temp,ans,nums);
        return ans;
    }
};