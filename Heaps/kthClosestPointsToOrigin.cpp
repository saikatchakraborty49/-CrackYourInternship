class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>>maxHeap;
        for(int i=0;i<points.size();i++){
            if(maxHeap.size()<k){
                vector<int>temp{points[i][0],points[i][1]};
                int dist=points[i][0]*points[i][0]+points[i][1]*points[i][1];
                maxHeap.push({dist,temp});
            }
            else{
                vector<int>temp{points[i][0],points[i][1]};
                int dist=points[i][0]*points[i][0]+points[i][1]*points[i][1];
                int top=maxHeap.top().first;
                if(dist<top){
                    maxHeap.pop();
                    maxHeap.push({dist,temp});
                }
            }
        }
        vector<vector<int>>ans;
        while(!maxHeap.empty()){
            auto temp=maxHeap.top().second;
            ans.push_back(temp);
            maxHeap.pop();
        }
        return ans;
    }
};