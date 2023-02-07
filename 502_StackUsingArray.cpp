#include <bits/stdc++.h>
using namespace std;

class StackUsingArray {
	int *data;
	int nextIndex;
	int capacity;

	public:
	StackUsingArray() {
		data = new int[5];
		nextIndex = 0;
		capacity = 5;
	}

	int size() {
		return nextIndex;
	}

	bool isEmpty() {
		return nextIndex == 0;
	}

	int pop() {
		if(isEmpty()) return -1;
		nextIndex--;
		return data[nextIndex];
	}

	void push(int value) {
		if(nextIndex == capacity) {
			int *newData = new int[capacity*2];
			for(int i=0; i<capacity; i++) newData[i] = data[i];
			capacity *= 2;
			delete [] data;
			data = newData;
		}
		data[nextIndex] = value;
		nextIndex++;
	}

	int top() {
		if(isEmpty()) return -1;
		return data[nextIndex-1];
	}
};

int main(){
	StackUsingArray s;
	s.push(1);
	s.push(2);
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
}