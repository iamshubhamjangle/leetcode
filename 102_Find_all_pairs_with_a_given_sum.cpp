/*
Find_all_pairs_with_a_given_sum.cpp

Given two unsorted arrays A of size N and B of size M of distinct elements, the task is to find all pairs from both arrays whose sum is equal to X.

Input:
A[] = {1, 2, 4, 5, 7}
B[] = {5, 6, 3, 4, 8} 
X = 9 
Output: 
1 8
4 5 
5 4

Input:
A[] = {-1, -2, 4, -6, 5, 7}
B[] = {6, 3, 4, 0} 
X = 8 
Output:
4 4 
5 3

https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x5808/1
    - Bruteforce: TC: O(N*M + NlogN) SC: O(N)
    - Unordered_map. TC: O(N log N) SC: O(N)
    - Binary Search.  TC: O(2*NlogN) SC: O(N) 

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // Bruteforce: TC: O(N*M + NlogN) SC: O(N)
    vector<pair<int,int>> allPairs1(int a[], int b[], int n, int m, int X) {
    	vector<pair<int, int>> ans;
        for(int i=0; i<n; i++) {
        	for(int j=0; j<m; j++) {
        		if(X - a[i] == b[j]) {
        			ans.push_back({a[i], b[j]});
        			break;
				}
        	}
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    // Unordered_map. TC: O(N log N) SC: O(N)
    vector<pair<int,int>> allPairs2(int a[], int b[], int n, int m, int X) {
    	vector<pair<int, int>> ans;
    	unordered_map<int, int> um;

    	for(int i=0; i<m; i++) {
    		um[b[i]]++;
    	}

    	for(int i=0; i<n; i++) {
    		if(um[X - a[i]]) ans.push_back({a[i], X - a[i]});
    	}

        sort(ans.begin(), ans.end());
    	return ans;
    }

    // Binary Search.  TC: O(2*NlogN) SC: O(N) 
    bool binarySearch(int a[], int low, int high, int X) {
    	if(low > high) return false;
    	int mid = low + (high - low) / 2;	//avoid overflow if INT

    	if(a[mid] == X)
    		return true;

    	if(X > a[mid])
    		return binarySearch(a, mid + 1, high, X);
    	else
    		return binarySearch(a, low, mid - 1, X);
    }

    vector<pair<int,int>> allPairs(int a[], int b[], int n, int m, int X) {
    	vector<pair<int, int>> ans;
    	sort(b, b+m);
    	for(int i=0; i<n; i++) {
    		int e = X - a[i];
    		if(binarySearch(b, 0, m-1, e))
    			ans.push_back({a[i], X-a[i]});
    	}
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
	long long t;
	cin >> t;
	
	while(t--){
	    int N, M, X;
	    cin >> N >> M >> X;
        int A[N], B[M];
        
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	   Solution ob;
	   vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	}
	return 0;
}