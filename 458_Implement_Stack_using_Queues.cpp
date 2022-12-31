/*
Implement_Stack_using_Queues.cpp

https://leetcode.com/problems/implement-stack-using-queues/
*/

#include <bits/stdc++.h>
using namespace std;

// class MyStack {
// public:
//     queue<int> q1, q2;

//     MyStack() {
//     }
    
//     void push(int x) {
// 		q2.push(x);
// 		while(!q1.empty()) {
// 			q2.push(q1.front()); q1.pop();
// 		}
// 		q1 = q2;
// 		q2 = {};
//     }
    
//     int pop() {
//     	int temp = q1.front(); q1.pop();
//     	return temp;
//     }
    
//     int top() {
//      	int temp = q1.front();
//     	return temp;   
//     }
    
//     bool empty() {
//         return q1.empty() && q2.empty();
//     }
// };


class MyStack {
public:
    queue<int> q;

    MyStack() {
    }
    
    void push(int x) {
		int n = q.size();
		q.push(x);
		while(n--) {
			q.push(q.front()); q.pop();
		}
    }
    
    int pop() {
    	int temp = q.front(); q.pop();
    	return temp;
    }
    
    int top() {
    	return q.front();   
    }
    
    bool empty() {
        return q.empty();
    }
};

int main(){
	MyStack st;
	st.push(1);
	st.push(2);
	st.push(3);
	cout << st.top() << endl;
	cout << st.pop() << endl;
	cout << st.top() << endl;
	cout << st.empty() << endl;
}
