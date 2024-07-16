class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<bool>arr(201,false);
        int cnt=0;
        for(auto i:nums){
            arr[i+100]=true;
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]){
                nums[cnt]=i-100;
                cnt++;
            }
        }
        return cnt;
    }
};