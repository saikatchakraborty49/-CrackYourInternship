class MyQueue {
public:
    void insertAtBottom(stack<int>&st,int x){
        if(st.empty()){
            st.push(x);
            return ;
        }
        int temp=st.top();
        st.pop();
        insertAtBottom(st,x);
        st.push(temp);
    }
    stack<int>st;
    MyQueue() {
        
    }
    
    void push(int x) {
        insertAtBottom(st,x);
    }
    
    int pop() {
        int ele=st.top();
        st.pop();
        return ele;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */