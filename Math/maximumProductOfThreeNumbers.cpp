class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int min1=nums[0];
        int min2=nums[1];
        int max1=nums[n-1];
        int max2=nums[n-2];
        int max3=nums[n-3];
        int ans1=max1*max2*max3;
        int ans2=min1*min2*max1;
        return max(ans1,ans2);
    }
};