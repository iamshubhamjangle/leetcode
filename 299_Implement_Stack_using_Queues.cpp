/*
Implement_Stack_using_Queues.cpp

Implement a last-in-first-out (LIFO) stack using only two queues. 
The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

https://leetcode.com/problems/implement-stack-using-queues/
*/

// // 1. TC: O(N) SC: O(2N)
// // Using two queues. Add to second q2 then add each element from q1 to q2 this will flip the elements
// class MyStack {
// public:
// 	queue<int> q1;
// 	queue<int> q2;

//     MyStack() {
        
//     }
    
//     void push(int x) {
//         q2.push(x);
//         while(!q1.empty()) {
//         	q2.push(q1.front());
//         	q1.pop();
//         }
//         q1 = q2;
//         q2 = {};
//     }
    
//     int pop() {
//     	int temp = q1.front();
//         q1.pop();
//         return temp;
//     }
    
//     int top() {
//         return q1.front();
//     }
    
//     bool empty() {
//         return q1.size() == 0;
//     }
// };


// 2. Using single queue.
class MyStack {
public:
	queue<int> q;

    MyStack() {
        
    }
    
    void push(int x) {
        int n = q.size();
        q.push(x);
        while(n--) {
        	q.push(q.front());
        	q.pop();
        }
    }
    
    int pop() {
    	int temp = q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */