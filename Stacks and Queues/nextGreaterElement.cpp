class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        st.push(INT_MIN);
        int n2=nums2.size();
        int n1=nums1.size();
        unordered_map<int,int>mpp;
        vector<int>ans2(n2);
        vector<int>ans1(n1);
        for(int i=n2-1;i>=0;i--){
            int ele=nums2[i];
            mpp[ele]=i;
            while(!st.empty() and ele>st.top()){
                st.pop();
            }
            if(!st.empty()) ans2[i]=st.top();
            else ans2[i]=-1;
            st.push(ele);
        }
        for(int i=0;i<n1;i++){
            ans1[i]=ans2[mpp[nums1[i]]];
        }
        return ans1;
    }
};