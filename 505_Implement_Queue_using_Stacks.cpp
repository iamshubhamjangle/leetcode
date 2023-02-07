/*
Implement_Queue_using_Stacks.cpp

https://leetcode.com/problems/implement-queue-using-stacks/
*/


class MyQueue {
public:
    stack<int> s1, s2;

    MyQueue() {}
    
    void push(int x) {
        while(!s2.empty()) {
            s1.push(s2.top()); 
            s2.pop();
        }
        s1.push(x);
    }
    
    int pop() {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int top = s2.top(); s2.pop();
        return top;
    }
    
    int peek() {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};


