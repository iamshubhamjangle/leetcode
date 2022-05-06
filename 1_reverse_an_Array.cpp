#include <bits/stdc++.h>
using namespace std;

/*
Reverse an Array
Method 1: time: O(N), space: O(1)
	- Keep two integer position start & end
	- while(start < end) swap both elements at start and end
	- decrement start and end

Reverse an array without using subtract sign ‘-‘ anywhere in the code
Method 1: 
	1- Store array elements into a vector in C++. 
	2- Then reverse the vector using predefined functions. 
	3- Then store reversed elements into the array back.
Method 2: 
	1- Store array elements into a stack. 
	2- As the stack follows Last In First Out, so we can store elements from 
	top of the stack into the array which will be itself in a reverse manner. 
Method 3: 
	1- In this method, the idea is to use a negative sign but by storing it into a variable. 
	2- By using this statement x = (INT_MIN/INT_MAX), we get -1 in a variable x. 
	3- As INT_MIN and INT_MAX have same values just of opposite signs, so on dividing them it will give -1. 
	4- Then ‘x’ can be used in decrementing the index from last.
*/

void solve();
void reverseArray(int[], int, int);

int main(){
	int t;
	cin >> t;		//input no. of test cases
	while(t--){
		solve();
		cout << endl;	//run this 't' times
	}
}

void solve() {
	int length;
	cin >> length;

	int arr[length];

	for(int i=0; i<length; i++){
		cin >> arr[i];
	}

	for(int j=length-1; j>=0; j--) {
		cout << arr[j] << " ";
	}

	cout << endl;

	reverseArray(arr, 0, length-1);

	// loop an array
	for(int i : arr) {
		cout << i << " ";
	}
}

void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}  