class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        pair<int,int>ele;
        ele.first=price;
        ele.second=1;
        while(!st.empty() and st.top().first<=price){
            ele.second+=st.top().second;
            st.pop();
        }
        st.push(ele);
        return st.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */