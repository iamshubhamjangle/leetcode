/*
Nearest_Smaller_Element.cpp

https://www.interviewbit.com/problems/nearest-smaller-element/
*/

#include <bits/stdc++.h>
using namespace std;

template<typename T>
void print(vector<T> &v) { cout << "vector<T> = ["; for(int i=0; i<v.size(); i++) { cout << v[i]; if(i<v.size()-1) cout << ","; } cout << "]" << endl; }

template<typename T>
void print(vector<vector<T>> &v) { int n = v.size(); int m = v[0].size(); cout << "vector<vector<T>> = ["; for(int i=0; i<n; i++) { cout << "["; for(int j=0; j<m; j++) {cout << v[i][j]; if(j<m-1) cout << ","; } cout << "]"; } cout << "]" << endl; }

// Brute. TC: O(N*N) SC: O(1)
vector<int> _prevSmaller(vector<int> &A) {
	int n = A.size();
	vector<int> res;

	for(int i=0; i<n; i++) {
		int prevSmallest = -1;
		for(int j=i-1; j>=0; j--) {
			if(A[j] < A[i]) {
				prevSmallest = A[j];
				break;
			}
		}
		res.push_back(prevSmallest);
	}

	return res;
}


// Using stack()
// If any element > curr, remove them
// If stack.empty() push(-1) else push(s.top());
// Push curr to stack
// TC: O(N) SC: O(N)
vector<int> prevSmaller(vector<int> &A) {
	int n = A.size();
	stack<int> s;
	vector<int> res(n, -1);

	for(int i=0; i<n; i++) {
		// maintain decreasing order stack
		while(!s.empty() && s.top() >= A[i]) s.pop();

		if(!s.empty()) res[i] = s.top();

		s.push(A[i]);
	}

	return res;
}


int main(){
	vector<int> A;
	vector<int> res;

	A = {4, 5, 2, 10, 8};
	res = prevSmaller(A);
	print(res);		// -1,4,-1,2,2
	A = {4, 5, 2, 4, 8};
	res = prevSmaller(A);
	print(res);		// -1,4,-1,2,4
	A = {3, 2, 1};
	res = prevSmaller(A);
	print(res);		//-1,-1,-1
	A = {39, 27, 11, 4, 24, 32, 32, 1};
	res = prevSmaller(A);
	print(res);		//-1,-1,-1,-1,4,24,24,-1
}
