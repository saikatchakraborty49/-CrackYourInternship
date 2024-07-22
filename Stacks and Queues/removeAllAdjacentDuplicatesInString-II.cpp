class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>>v;
        for(int i=0;i<s.size();i++){
            if(v.size()!=0 and s[i]==v.back().first) v.back().second++;
            else v.push_back({s[i],1});
            if(v.back().second==k) v.pop_back();
        }
        string ans;
        for(auto i:v){
            ans.append(i.second,i.first);
        }
        return ans;
        // stack<int>st;
        // stack<int>temp;
        // for(int i=0;i<s.size();i++){
        //     st.push(s[i]);
        //     if(st.size()>=k){
        //         int ele=st.top();
        //         temp.push(ele);
        //         st.pop();
        //         int cnt=1;
        //         while(cnt!=k and ele==st.top()){
        //             ele=st.top();
        //             st.pop();
        //             temp.push(ele);
        //             cnt++;
        //         }
        //         if(cnt!=k){
        //             while(!temp.empty()){
        //                 st.push(temp.top());
        //                 temp.pop();
        //             }
        //         }
        //         else{
        //             while(!temp.empty())
        //             temp.pop();
        //             // i=i+k-1;
        //         }
        //     }
        // }
        // string ans;
        // while(!st.empty()){
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        // reverse(ans.begin(),ans.end());
        // return ans;
    }
};