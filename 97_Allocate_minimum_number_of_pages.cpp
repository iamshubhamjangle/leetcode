/*
Allocate_minimum_number_of_pages.cpp

You are given N number of books. Every ith book has Ai number of pages. The books are arranged in ascending order.
You have to allocate contiguous books to M number of students. There can be many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is the minimum of those in all the other permutations and print this minimum value.
Each book will be allocated to exactly one student. Each student has to be allocated at least one book.
Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

Example 1:
Input  : N = 4, A[] = {12,34,67,90}, M = 2
Output :113
Explanation:Allocation can be done in 
following ways:{12} and {34, 67, 90} 
Maximum Pages = 191{12, 34} and {67, 90} 
Maximum Pages = 157{12, 34, 67} and {90} 
Maximum Pages =113. Therefore, the minimum 
of these cases is 113, which is selected 
as the output

Input:
N = 3
A[] = {15,17,20}
M = 2
Output:32
Explanation: Allocation is done as
{15,17} and {20}


https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1/#
	- Method: Binary Search O(N). SC: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    bool isValid(int arr[], int n, int k, int maxPages) {
    	int studentNeeded = 1;
    	int sum = 0;
    	for(int i=0; i<n; i++) {
    		sum += arr[i];
    		if(sum > maxPages) {
    			studentNeeded++;
    			sum = arr[i];	// reset sum to curr for new student
    		}
    		if(studentNeeded > k)
    			return false;
    	}
    	return true;
    }

    int findPages(int arr[], int n, int k)  {
    	int maxInArray = INT_MIN;
    	int sum = 0;
    	for(int i=0; i<n; i++) {
    		if(arr[i] > maxInArray) maxInArray = arr[i];
    		sum += arr[i];
    	}

        int start = maxInArray;
        int end = sum;

        int answer = -1;
        while(start <= end) {
        	int mid = start + (end - start) / 2;
        	if(isValid(arr, n, k, mid)) {
        		answer = mid;
        		end = mid - 1;	// Going left as to optimise the solution the current mid is valid max pages of book
        	} else {
        		start = mid + 1;	// Going right as current mid is not valid bze students needed > maxStudent available
        	}
        }

        return answer;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}