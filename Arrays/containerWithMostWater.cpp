class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int i=0;
        int j=height.size()-1;
        while(i<j){
            ans=max(ans,min(height[j],height[i])*(j-i));
            if(height[j]<height[i]) j--;
            else i++;
        }
        return ans;
    }
};