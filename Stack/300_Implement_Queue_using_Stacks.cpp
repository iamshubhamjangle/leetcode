/*
Implement_Queue_using_Stacks.cpp

https://leetcode.com/problems/implement-queue-using-stacks/
*/


// // Using two stacks. TC: O(N) SC: O(2N)
// class MyQueue {
// public:
// 	stack<int> s1;
// 	stack<int> s2;

//     MyQueue() {
        
//     }

//	   TC: O(N)
//     void push(int x) {
//         while(!s1.empty()) {
//         	s2.push(s1.top());
//         	s1.pop();
//         }
//         s1.push(x);
//         while(!s2.empty()) {
//         	s1.push(s2.top());
//         	st.pop();
//         }
//     }
    
//     int pop() {
//     	int n = s1.top();
//         s1.pop();
//         return n;
//     }
    
//     int peek() {
//         return s1.top();
//     }
    
//     bool empty() {
//         return s1.empty();
//     }
// };


// Using two stacks. TC: O(N) SC: O(2N)
class MyQueue {
public:
	stack<int> input;
	stack<int> output;

    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
	    // shift input to output 
	    if (output.empty())
	      while (input.size())
	        output.push(input.top()), input.pop();

	    int x = output.top();
	    output.pop();
	    return x;
    }
    
    int peek() {
	    // shift input to output 
	    if (output.empty())
	      while (input.size())
	        output.push(input.top()), input.pop();

	    int x = output.top();
	    return x;
    }
    
    bool empty() {
        return (input.empty() && output.empty());
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