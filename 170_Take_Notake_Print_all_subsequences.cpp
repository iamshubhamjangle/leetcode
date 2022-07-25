/*
Take_Notake_Print_all_subsequences.cpp

Input: 
int arr[] = {3,1,2};
int n = 3;

Output: 
3 1 2 
3 1 
3 2 
3 
1 2 
1 
2 
{}

*/

#include <bits/stdc++.h>
using namespace std;

void printSubsequences(int i, int arr[], int n, vector<int> &ds) {
	if(i == n) {
		for(auto it: ds)
			cout << it <<" ";

		if(ds.size() == 0)
			cout << "{}";

		cout << endl;
		return;
	}

	// take
	ds.push_back(arr[i]);
	printSubsequences(i+1, arr, n, ds);
	ds.pop_back();

	// no take
	printSubsequences(i+1, arr, n, ds);
}


int main(){
	int arr[] = {3,1,2};
	int n = 3;
	vector<int> ds;
	printSubsequences(0, arr, n, ds);	
}