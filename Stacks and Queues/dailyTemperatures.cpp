class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            int ele=temperatures[i];
            while(st.top()!=-1 and ele>=temperatures[st.top()]){
                st.pop();
            }
            if(st.top()!=-1)
            ans[i]=st.top()-i;
            else 
            ans[i]=0;
            st.push(i);
        }
        return ans;
    }
};