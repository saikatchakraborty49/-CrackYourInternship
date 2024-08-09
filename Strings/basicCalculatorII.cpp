class Solution {
public:
    int calculate(string s) {
        long long number=0;
        char op='+';
        stack<long long> st;
        for(int i=0;i<s.size();i++){
            if(s[i]>='0' and s[i]<='9'){
                number=number*10+(s[i]-'0');
            }
            if(i==s.size()-1 || ((s[i]<'0' or s[i]>'9') and s[i]!=' ')){
                if(op=='+'){
                    st.push(number);
                }
                else if(op=='-'){
                    st.push(-1*number);
                }
                else if(op=='*'){
                    long long n2=st.top();
                    st.pop();
                    st.push(n2*number);
                }
                else if(op=='/'){
                    long long n2=st.top();
                    st.pop();
                    st.push(n2/number);
                }
                number=0;
                op=s[i];
            }
        }
        long long ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};