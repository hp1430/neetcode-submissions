class MinStack {
private:
    stack<int>primary, mini;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        primary.push(val);
        if(mini.empty() || val<=mini.top()) mini.push(val);
    }
    
    void pop() {
        if(primary.top() == mini.top()) mini.pop();
        primary.pop();
    }
    
    int top() {
        return primary.top();
    }
    
    int getMin() {
        return mini.top();
    }
};
