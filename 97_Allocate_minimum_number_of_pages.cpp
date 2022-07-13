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

class Solution {
    public:
    bool isValid(int arr[], int n, int noStudents, int maxPages) {
        int stu = 1;
        int currPages = 0;

        for(int i=0; i<n; i++) {
            currPages += arr[i];
            if(currPages > maxPages) {
                stu++;
                currPages = arr[i]; //reset sum to currPages for new student
            }
            if(stu > noStudents)
                return false;
        }

        return true;
    }

    // minimize the max no of pages assigned to each student
    // binary search space will contain max pages book one student can have ---- all book pages single one can have
    int findPages(int arr[], int n, int k)  {
        int l = arr[n-1];
        int h = accumulate(arr, arr+n, 0);
        int res = -1;

        // edge conditions
        if(n<k) return res;     // # students > # books

        while(l<=h) {
            int mid = l + (h-l)/2;
            if(isValid(arr, n, k, mid)) {
                res = mid;         // as we can loose the mid
                h = mid-1;
            } else {
                l = mid+1;
            }
        }

        return res;
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
  // } Driver Code Ends