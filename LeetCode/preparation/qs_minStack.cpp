class MinStack {
    vector <pair<int, int>> data;
public:
    /** initialize your data structure here. */
    MinStack() {
        vector <pair<int,int>> d; 
        this->data = d; 
    }
    
    void push(int x) {
        if(data.empty()) data.push_back({x, x});
        else{
            int tmp = data.back().second;
            if(tmp < x) data.push_back({x, tmp});
            else data.push_back({x, x});
        }
    }
    
    void pop() {
        if(!data.empty()) data.pop_back();
    }
    
    int top() {
        return data.back().first;
    }
    
    int getMin() {
        return data.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */