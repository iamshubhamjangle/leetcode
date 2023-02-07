/*
504_Implement_Stack_using_Queues.cpp

https://leetcode.com/problems/implement-stack-using-queues/description/
*/

class MyStack {
public:
    queue<int> q;

    MyStack() {}
    
    void push(int x) {
        int len = q.size();
        q.push(x);
        while(len--) {
            int top = q.front(); q.pop();
            q.push(top);
        }
    }
    
    int pop() {
        if(empty()) return -1;
        int top = q.front(); q.pop();
        return top;
    }
    
    int top() {
        if(empty()) return -1;
        return q.front();
    }
    
    bool empty() {
        return q.size() == 0;
    }
};





