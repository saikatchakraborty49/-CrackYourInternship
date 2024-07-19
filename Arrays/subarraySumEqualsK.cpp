class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        int sum=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int toFind=sum-k;
            if(sum==k) cnt++;
            if(mpp.find(toFind)!=mpp.end()){
                cnt+=mpp[toFind];
            }
            mpp[sum]++;
        }
        return cnt;
    }
};