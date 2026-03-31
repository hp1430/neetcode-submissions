class MinStack {
private:
    vector<int>st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        int mini = INT_MAX;
        for(int i=0; i<st.size(); i++) if(mini > st[i]) mini = st[i];
        return mini;
    }
};
