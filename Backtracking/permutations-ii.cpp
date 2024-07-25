class Solution {
private:
    void solve(vector<int> &nums,int index,vector<vector<int>>&ans){
        if(index==nums.size()){
            ans.push_back(nums);
            return ;
        }
        //repeatative numbers se bachne ki liye
        unordered_map<int,int>mpp;
        for(int i=index;i<nums.size();i++){
            if(mpp.find(nums[i])!=mpp.end()) continue;
            mpp[nums[i]]++;
            swap(nums[i],nums[index]);
            solve(nums,index+1,ans);
            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        int index=0;
        solve(nums,index,ans);
        return ans;
    }
};