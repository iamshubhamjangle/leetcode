/*
Find_K_Closest_Elements.cpp

Given a sorted integer array arr, two integers k and x, return the k closest 
integers to x in the array. The result should also be sorted in ascending order.

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]

https://leetcode.com/problems/find-k-closest-elements/
*/

class Solution {
public:
	// // Bruteforce. Find difference and sort. TC: O(N + 2NlogN) SC: O(N)
	// vector<int> findClosestElements(vector<int>& arr, int k, int x) {
	//        int n = arr.size();
	//        vector<pair<int,int>> v;

	//        for(int i=0; i<n; i++) {
	//            v.push_back({ abs(arr[i]-x), arr[i] });
	//        }

	//        sort(v.begin(), v.end());

	//        vector<int> ans;
	//        for(int i=0; i<k; i++) {
	//            ans.push_back(v[i].second);
	//        }

	//        sort(ans.begin(), ans.end());

	//        return ans;
	//    }

    
    // Heap. TC: O(NlogK + NlogK) SC: O(N)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    	int n = arr.size();
    	priority_queue<pair<int,int>> pq;	//maxheap: {Difference, Value}

    	for(int i=0; i<n; i++) {
    		pq.push({ abs(x-arr[i]), arr[i] });		// store the elements by minimum difference at bottom
    		if(pq.size() > k) pq.pop();				// remove the max difference element
    	}

    	vector<int> ans;
    	while(!pq.empty()) {
    		ans.push_back(pq.top().second);
    		pq.pop();
    	}

    	sort(ans.begin(), ans.end());	// as the pq was sorted by difference we need to sort by value.

    	return ans;
    }
};