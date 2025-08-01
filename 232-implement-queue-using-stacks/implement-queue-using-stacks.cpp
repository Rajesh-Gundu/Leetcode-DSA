class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        while(!s1.empty())
            s1.pop();

        while(!s2.empty())
            s2.pop();
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()) {
            shiftS1toS2();
        }
        int cur = s2.top();
        s2.pop();
        return cur;
    }
    
    int peek() {
        if(s2.empty()) {
            shiftS1toS2();
        }
        return s2.top();
    }
    
    bool empty() {
        return (s1.empty() && s2.empty());
    }

    void shiftS1toS2() {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
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