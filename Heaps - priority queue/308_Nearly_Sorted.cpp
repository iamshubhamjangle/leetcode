/*
Nearly_Sorted.cpp

Sample Input 1:
1
7 3 
6 5 3 2 8 10 9
Sample Output 1:
2 3 5 6 8 9 10

Sample Input 2:
1
8 4
10 9 8 7 4 70 60 50
Sample Output 2:
4 7 8 9 10 50 60 70

https://www.codingninjas.com/codestudio/problems/nearly-sorted_982937
*/

#include <bits/stdc++.h> 

vector<int> nearlySorted(vector<int> arr, int n, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int idx = 0;

    for(int i=0; i<n; i++) {
        pq.push(arr[i]);
        if(pq.size() > k) {
            arr[idx] = pq.top();
            pq.pop();
            idx++;
        }
    }

    while(!pq.empty() && idx < n) {
        arr[idx] = pq.top(); pq.pop();
        idx++;
    }

    return arr;
}