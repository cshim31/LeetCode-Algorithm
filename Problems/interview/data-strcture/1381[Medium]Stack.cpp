class CustomStack {
public:
    vector<int> stack;
    int maxSize;
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(stack.size() < maxSize) stack.push_back(x);
    }
    
    int pop() {
        if(stack.size() > 0){
            int element = stack.back();
            this->stack.pop_back();
            return element;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        
        int index = min<int>(k - 1,stack.size() - 1);
        while(index >= 0) {
            stack[index] += val;
            index--;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */