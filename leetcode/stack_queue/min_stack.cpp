class MinStack {
    vector<pair<int,int>> nums;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(this->nums.empty()){
            this->nums.push_back({val,val});
            return;
        }
        if(val<=this->nums.back().second){
            this->nums.push_back({val,val});
        }else{
            this->nums.push_back({val,this->nums.back().second});
        }
    }
    
    void pop() {
        this->nums.pop_back();
    }
    
    int top() {
        return this->nums.back().first;
    }
    
    int getMin() {
        return this->nums.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
