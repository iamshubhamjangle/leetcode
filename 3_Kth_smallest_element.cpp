/*
Kth smallest element 

Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Input:
N = 6
arr[] = 7 10 4 3 20 15
K = 3
Output : 7

https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

Method 1: Using sort - O(N log N)
    - use sort()
    - then return k - 1

Method 2: Using min or max heap - priority queue O(K log N) + O(N)
    - create min heap -- push all element to pq
    - pop elements k times
    - k+1 th element will be the answer
    - for larger K use min Heap / smaller K use max heap

Method 3: Quickselect Algorithm - O(n)
*/

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function

#include<bits/stdc++.h>
using namespace std;

// class Solution{
//     public:
//     int kthSmallest(int arr[], int l, int r, int k) {
//       sort(arr, arr + r + 1);
//       return arr[k-1];
//     }
// };

// C++ Easy solution using a priority_queue, Min Heap 
// Time O(N) -- building head + O(KlogN) --- heapifying
class Solution{
    public:
    // int kthSmallest(int arr[], int l, int r, int k) {
    //   priority_queue<int,vector<int>, greater<int>> pq;
    //    for(int i=l;i<=r; i++){
    //        pq.push(arr[i]);
    //    }    //push all element to pq
    //    for(int i=1;i<k;i++){
    //        pq.pop();
    //    }    //pop elements k times
    //    int ans=pq.top();    // k+1th element will be the answer
    //    return ans;
    // }
};

int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}