class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>minHeap;
        int n=nums.size();
        for(int i=0;i<k;i++){
            minHeap.push(nums[i]);
        }
        for(int i=k;i<n;i++){
            int ele=nums[i];
            if(ele>minHeap.top()){
                minHeap.pop();
                minHeap.push(ele);
            }
        }
        return minHeap.top();
    }
};