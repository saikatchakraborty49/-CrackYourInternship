class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element=nums[0];
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(element==nums[i]){
                cnt++;
            }
            else{
                if(cnt==0){
                    element=nums[i];
                    cnt=1;
                }
                else{
                    cnt--;
                }
            }
        }
        return element;
    }
};