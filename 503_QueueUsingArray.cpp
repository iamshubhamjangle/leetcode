/*
push(x) -> If count == capacity: Queue is full, else push at rear%capacity.  rear++; count++;
pop() -> if front == rear%capacity || count == 0: Queue is empty. else pop[front%capacity]. front++; count--;
top() -> if count == 0: Queue is empty. else return arr[front%capacity]
*/
#include <bits/stdc++.h>
using namespace std;

class QueueUsingArray {
	int *arr;
	int capacity;
	int count;
	int front, rear;

public:
	QueueUsingArray() {
		arr = new int[5];
		capacity = 5;	// Total Capacity
		count = 0;		// Current elements
		front = 0;		// Front pointer
		rear = 0;		// Rear pointer
	}

	void push(int x) {
		if(count == capacity) return;
		arr[rear%capacity] = x;
		count++;
		rear++;
	}

	void pop() {
		if(count == 0) return;
		arr[front%capacity] = -1;
		front++;
		count--;
	}

	int top() {
		if(count == 0) return -1;
		return arr[front%capacity];
	}
};


int main(){
	QueueUsingArray q;	
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	q.push(7);
	cout << q.top() << endl;
	q.pop();
	q.pop();
	cout << q.top() << endl;
}
