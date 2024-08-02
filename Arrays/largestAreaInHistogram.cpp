class Solution {
private:
    void findPrevSmaller(vector<int>&heights,vector<int>&prevSmaller,int n){
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++){
            while(st.top()!=-1 and heights[i]<=heights[st.top()]){
                st.pop();
            }
            prevSmaller[i]=st.top();
            st.push(i);
        }
    }
    void findNextSmaller(vector<int>&heights,vector<int>&nextSmaller,int n){
        stack<int>st;
        st.push(n);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=n and heights[i]<=heights[st.top()]){
                st.pop();
            }
            nextSmaller[i]=st.top();
            st.push(i);
        }
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>prevSmaller(n);
        vector<int>nextSmaller(n);
        findPrevSmaller(heights,prevSmaller,n);
        findNextSmaller(heights,nextSmaller,n);
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,heights[i]*(nextSmaller[i]-prevSmaller[i]-1));
        }
        return ans;
    }
};