class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>mpp;
        int sum=0;
        int n=nums.size();
        mpp[0]=1;
        int cnt=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            cnt+=mpp[(sum%k+k)%k];
            mpp[(sum%k+k)%k]++;
        }
        return cnt;
    }
};