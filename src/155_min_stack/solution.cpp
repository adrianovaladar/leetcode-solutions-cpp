class MinStack {
std::vector<int> stack;
static int min;
public:
    MinStack() {
    }
    
    void push(int val) {
        if (stack.empty()) min = val;
        if (min > val) min = val;
        stack.emplace_back(val);
    }
    
    void pop() {
        stack.pop_back();
        min = *std::min_element(stack.begin(), stack.end());
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min;
    }
};

int MinStack::min;

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
