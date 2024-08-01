class Solution {
public:
    string simplifyPath(string path) {
        stack<char>st;
        while(path.size()!=0 and path.back()=='/')
        path.pop_back();
        for(int i=0;i<path.size();i++){
            if(!st.empty() and path[i]=='/' and st.top()=='/')continue;
            if(!st.empty() and path[i]=='.' and st.top()=='/'){
                if(i+1>=path.size() or path[i+1]=='/'){
                    // cout<<"idhar aaya"<<endl; 
                    continue;
                }
                else if(path[i+1]=='.' and ((path.size()-(i+2))==0 or path[i+2]=='/')){
                    // cout<<"idhar aaya"<<endl;
                    if(st.size()>1)
                    st.pop();
                    while(!st.empty() and st.top()!='/'){
                        st.pop();
                    }
                    i+=1;
                    continue;
                }
            }
            st.push(path[i]);
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        if(ans.size()==0) return "/";
        reverse(ans.begin(),ans.end());
        if(ans.size()!=1 and ans.back()=='/') ans.pop_back();
        return ans;
    }
};