class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        if(q.empty()) return -1;
        int n=q.size()-1;
        while(n--){
            int ele=q.front();
            q.pop();
            q.push(ele);
        }
        int ans=q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        if(q.empty()) return -1;
        int n=q.size()-1;
        while(n--){
            int ele=q.front();
            q.pop();
            q.push(ele);
        }
        int ans=q.front();
        q.pop();
        q.push(ans);
        return ans;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */