/*
Sum_of_elements_between_k1'th_and_k2'th_smallest_elements.cpp

Given an array A[] of N positive integers and two positive integers K1 and K2. 
Find the sum of all elements between K1th and K2th smallest elements of the 
array. It may be assumed that (1 <= k1 < k2 <= n).

Input : N  = 7, , A[] = {20, 8, 22, 4, 12, 10, 14}, K1 = 3, K2 = 6
Output: 26

Input : N = 6, A[] = {10, 2, 50, 12, 48, 13}, K1= 2, K2 = 6
Output: 73

Sum_of_elements_between_k1'th_and_k2'th_smallest_elements.cpp
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution{
    public:
    int findSmallest(ll A[], ll n, ll k) {
    	priority_queue<int> pq; 		// max heap

    	for(int i=0; i<n; i++) {
    		pq.push(A[i]);
    		if(pq.size() > k) pq.pop();
    	}

    	return pq.top();
    }

    ll sumBetweenTwoKth(ll A[], ll N, ll K1, ll K2) {
        int a = findSmallest(A, N, K1);
        int b = findSmallest(A, N, K2);
        ll sum = 0;
        for(int i=0; i<N; i++) {
        	if(a < A[i] && A[i] < b) {
        		sum += A[i];
        	}
        }
        return sum;
    }
};

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}