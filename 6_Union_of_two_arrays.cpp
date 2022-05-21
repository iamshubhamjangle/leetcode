/*
Union_of_two_arrays - find the count for merged (union) arrays and ignore duplicates

Given two arrays a[] and b[] of size n and m respectively. The task is to find union between these two arrays.

Union of the two arrays can be defined as the set containing distinct elements from both the arrays. 
If there are repetitions, then only one occurrence of element should be printed in the union.

Input:
5 3
1 2 3 4 5
1 2 3
Output: 
5

Input:
6 2 
85 25 1 32 54 6
85 2 
Output: 
7

https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1

Method 0: merge a,b -> sort -> compare - time: O(N log N), space: O(N)
	- merge a,b into c. sort c. 
	- compare adjacent elements and increase the count if(adjacent are not equal)
Method 1: unordered_set  time: O(N), space O(N) 
	- use unordered_set, add all the elements and return the count

*/

#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    // Method 1: merge, sort, compare
    // int doUnion(int a[], int n, int b[], int m)  {
    //     int mergedArray[m + n];

    //     int i;
    //     for(i=0; i<n; i++) {
    //     	mergedArray[i] = a[i];
    //     }

    //     for(int j=0; j<m; j++) {
    //     	mergedArray[i++] = b[j];
    //     }

    //     sort(mergedArray, mergedArray + m + n);

    //     int count = 0;
    //     for(int j=0; j<(m+n); j++) {
    //     	if(j == (m+n-1)) {
    //     		count++;
    //     		break;
    //     	}
    //     	if(mergedArray[j] != mergedArray[j+1]) {
    //     		count++;
    //     	}
    //     }

    //     return count;
    // }

	// Method 2: unordered_set
    int doUnion(int a[], int n, int b[], int m)  {
        unordered_set<int> us;
        for(int i=0; i<n; i++) {
        	us.insert(a[i]);
        }
        for(int i=0; i<m; i++) {
        	us.insert(b[i]);
        }
        return us.size();
    }
};

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}