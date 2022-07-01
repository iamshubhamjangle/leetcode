/*
Count_distinct_elements_in_every_window.cpp

Given an array of integers and a number K. Find the count of distinct 
elements in every window of size K in the array.

Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3

Input:
N = 3, K = 2
A[] = {4,1,1}
Output: 2 1

https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1
Method 1: Bruteforce. TC: O(N*K*K) SC: O(1)
    - loop from (0 to n-k) ie. through each window.
    - for each window bruteforce to check duplicates
Method 2: Sets. TC: O(N*K) SC: O(N)
	- loop and iterate each window. Use set<int> to count unique.
Method 3: Sliding Window. TC: O(N) SC: O(N)
    - Keep a distinct count and unordered_map
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    /*
    // Method 1: TC: O(N*K*K) SC: O(1)
    int numberOfFindUniqueIntegers(int arr[], int k) {
        int distinct = 0;
        for(int i=0; i<k; i++) {
            bool duplicateFound = false;
            for(int j=i+1; j<k; j++) {
                if(arr[i] == arr[j]) {
                    duplicateFound = true;
                    break;
                }
            }
            if(!duplicateFound)
                distinct++;
        }
        return distinct;
    }

    vector<int> countDistinct (int arr[], int n, int k) {
        vector<int> ans;

        for(int i=0; i<=n-k; i++) {
            int n = numberOfFindUniqueIntegers(arr + i, k);
            ans.push_back(n);
        }

        return ans;
    }
    */


    /* 
    // Method 2 TC: O(N*K) SC: O(N)
    int numberOfFindUniqueIntegers(int arr[], int k) {
        set<int> s;
        for(int i=0; i<k; i++) {
            s.insert(arr[i]);
        }
        return s.size();
    }

    vector<int> countDistinct (int arr[], int n, int k) {
        vector<int> ans;

        for(int i=0; i<=n-k; i++) {
            int n = numberOfFindUniqueIntegers(arr + i, k);
            ans.push_back(n);
        }

        return ans;
    }
    */


    // Method 3: sliding window. TC: O(N) SC: O(N)
    int distinct = 0;
    unordered_map<int, int> um;

    void add(int element) {
        // If the element we want to add doesnt exist, its distinct++;
        // add the element to unordered_map for reference
        if(!um[element])    
            distinct++;
        um[element]++;
    }

    void remove(int element) {
        // if element was present remove it from map
        // after removing if the count is zero our distinct--
        if(um[element])
            um[element]--;
        if(!um[element])
            distinct--;
    }

    vector<int> countDistinct (int arr[], int n, int k) {
        vector<int> ans;

        // add first window to map; also calculate distinct;
        for(int i=0; i<k; i++) {
            add(arr[i]);
        }

        // push answer of first window
        ans.push_back(distinct);

        // Iterate through rest of array
        for(int i=k; i<n; i++) {
            remove(arr[i-k]);       // remove the out of scope element
            add(arr[i]);            // add current to um & calculate distinct
            ans.push_back(distinct);
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}