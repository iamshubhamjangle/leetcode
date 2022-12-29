/*
merge_sort.cpp
TC: O(NlogN)
SC: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int l, int m, int h) {
	// L <-- A[l...m], R <-- A[m+1...h]
	int n1 = m - l + 1;
	int n2 = h - m;

	int L[n1], R[n2];

	for(int i=0; i<n1; i++) L[i] = v[l + i];
	for(int i=0; i<n2; i++) R[i] = v[m + 1 + i];

	int i = 0;	// L
	int j = 0;	// R
	int k = l;	// vector v

	while(i < n1 && j < n2) {
		if(L[i] < R[j])
			v[k++] = L[i++];
		else
			v[k++] = R[j++];
	}

	// rest of element left in L or R array
	while(i < n1) v[k++] = L[i++];
	while(j < n2) v[k++] = R[j++];
}

void mergesort(vector<int> &v, int l, int h) {
	if(l >= h) return;
	int mid = l + (h-l)/2;
	mergesort(v, l, mid);
	mergesort(v, mid+1, h);
	merge(v, l, mid, h);
}

void print(vector<int> &v) { for(auto i: v) cout << i << ", "; cout << endl; }

int main(){
	vector<int> v = {25,6,20,7,8,4,36,7,8,32,1,1};
	mergesort(v, 0, v.size() - 1);
	print(v);
	return 0;
}

