class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // if(ladders==0 and bricks==0) return 0;
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(0);
        int n=heights.size();
        // int i=1;
        int ans=0;
        for(int i=1;i<n;i++){
            if(heights[i]>heights[i-1]){
                int diff=abs(heights[i]-heights[i-1]);
                if(pq.size()<ladders){
                    pq.push(diff);
                }
                else{
                    int maxi;
                    int mini;
                    if(ladders!=0){
                        int top=pq.top();
                        pq.pop();
                        maxi=max(top,diff);
                        mini=min(top,diff);
                    }
                    else
                    mini=diff;
                    bricks-=mini;
                    if(bricks<0)
                    break;
                    if(ladders!=0)
                    pq.push(maxi);
                }
            }
                ans++;
        }
        return ans;
    }
};