class Solution {
private:
    void toNumber(vector<int>&numbers,vector<string>&tokens){
        for(auto i:tokens){
            if(i!="*"  and i!="/"   and i!="-" and i!="+"){
                int num=0;
                for(int j=i.size()-1;j>=0;j--){
                    if(i[j]=='-')
                    num*=-1;
                    else
                    num=num+(i[j]-'0')*pow(10,i.size()-1-j);
                }
                numbers.push_back(num);
            }
            else{
                if(i=="+")
                numbers.push_back(201);
                else if(i=="-")
                numbers.push_back(202);
                else if(i=="*")
                numbers.push_back(203);
                else if(i=="/")
                numbers.push_back(204);
            }
        }
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        vector<int>numbers;
        // toNumber(numbers,tokens);
        for(auto i:tokens){
            if(i!="*"  and i!="/"   and i!="-" and i!="+")
            numbers.push_back(stoi(i));
            else{
                if(i=="+")
                numbers.push_back(201);
                else if(i=="-")
                numbers.push_back(202);
                else if(i=="*")
                numbers.push_back(203);
                else if(i=="/")
                numbers.push_back(204);
            }
        }
        // for(auto i:numbers) cout<<i<<" ";
        for(auto i:numbers){
            if(i<=200){
                st.push(i);
            }
            else{
                int a=st.top(); st.pop();
                int b=st.top(); st.pop();
                if(i==201){
                    st.push(b+a);
                }
                else if(i==202){
                    st.push(b-a);
                }
                else if(i==203){
                    st.push(b*a);
                }
                else if(i==204){
                    st.push(b/a);
                }
            }
        }
        return st.top();
    }
};