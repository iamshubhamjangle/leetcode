/*
Number_of_pairs.cpp

Given two arrays X and Y of positive integers, find the number of pairs such 
that xy > yx (raised to power of) where x is an element from X and y is an element from Y.

Input: 
M = 3, X[] = [2 1 6] 
N = 2, Y[] = [1 5]
Output: 3		//2 1, 2 5, 6 1

Input: 
M = 4, X[] = [2 3 4 5]
N = 3, Y[] = [1 2 3]
Output: 5

https://practice.geeksforgeeks.org/problems/number-of-pairs-1587115620/1
   - Method 1: Bruteforce. TC: O(N*N) SC: O(1)
   - Method 2: Using Binary Search. TC: O(N log N) SC: O(1)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Method 1: Bruteforce. TC: O(N*N) SC: O(1)
    long long countPairs1(int x[], int y[], int m, int n) {
		long long int count = 0;
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				if(pow(x[i], y[j]) > pow(y[j], x[i]))
					count++;
			}
		}
		return count;
    }

    // Method 2: Using Binary Search. TC: O(N log N) SC: O(1)
    /* For most of cases Y > X will be enough to determine x^y > y^x
    ** Exceptions are for 0, 1, 2
    ** When x[i] == 0 -> no change in count
    ** When x[i] == 1 -> find 0's in y[]   -> count++;
    ** When x[i] == 2 -> find 3 & 4 in y[] -> count--;
    ** When x[i] == 3 -> find 2 in y[] -> count--;
    */ 
    long long countPairs(int X[], int Y[], int M, int N)
    {
    	int c = count(Y, Y+N, 3);
        long long s = (M-count(X, X+M, 1))*count(Y, Y+N, 1); 
        sort(Y, Y+N);
       	for(int i = 0; i<M; i++){
            if(X[i] == 1) continue;
            if(X[i] == 2) X[i] = 4;
            if(X[i] == 3) X[i] = 1, s -= c;
            s += N-(upper_bound(Y, Y+N, X[i])-Y);
        }
        return s;
    }
};

int main() {
	int T;
	cin>>T;
	while(T--) {
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++) {
			cin>>a[i];
		}
		for(i=0;i<N;i++) {
			cin>>b[i];
		}
		Solution ob;
		cout<<ob.countPairs(a, b, M, N)<<endl;
	}
}