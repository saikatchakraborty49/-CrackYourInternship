class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int>st;
        int n=nums.size();
        st.push(nums[0]);
        for(int i=1;i<n;i++){
            int ele=nums[i];
            while(!st.empty() and ele<st.top() and n-i-1>=k-st.size()){
                st.pop();
            }
            if(st.size()!=k) st.push(ele);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};