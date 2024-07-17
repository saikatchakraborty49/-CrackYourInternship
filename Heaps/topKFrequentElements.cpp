class Solution {
public:
    struct myComp{
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            return a.first>b.first;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,pair<int,bool>>mpp;
        vector<pair<int,int>>storeCnt;
        for(auto i:nums){
            int cnt=mpp[i].first;
            mpp[i]={cnt+1,false};
        }
        for(auto i:nums){
            if(mpp[i].second==false){
                storeCnt.push_back({mpp[i].first,i});
                mpp[i].second=true;
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,myComp>minHeap;
        for(int i=0;i<k;i++){
            minHeap.push(storeCnt[i]);            
        }
        for(int i=k;i<storeCnt.size();i++){
            if(storeCnt[i].first>minHeap.top().first){
                minHeap.pop();
                minHeap.push(storeCnt[i]);
            }
        }
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};