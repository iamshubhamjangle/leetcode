/*
Top_K_Frequent_Elements.cpp

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Input: nums = [1], k = 1
Output: [1]

https://leetcode.com/problems/top-k-frequent-elements/
*/


class Solution {
public:
	// // Map, reverse sort, return. TC: O(NlogN) SC: O(2N)
 //    vector<int> topKFrequent(vector<int>& nums, int k) {
 //        int n = nums.size();
 //        unordered_map<int,int> um;

 //        for(int i=0; i<n; i++) 
 //        	um[nums[i]]++;

 //        vector<pair<int,int>> v;
 //        for(auto i: um) {
 //        	v.push_back({i.second, i.first});
 //        }

 //        sort(v.rbegin(), v.rend());

 //        vector<int> ans;
 //        for(int i=0; i<k; i++) {
 //        	ans.push_back(v[i].second);
 //        }

 //        return ans;

 //    }

    
    // Map, Heap, Return. TC: O(NlogK) SC: O(2N)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (auto num : nums) freq[num]++;

        // min heap as we need most freq. we will remove minimum frequency
        typedef pair<int, int> pii;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(auto [a,b]: freq) {						// for(auto i: freq) {
        	pq.push({b,a});							// 	pq.push({ i.second, i.first });
        	if(pq.size() > k) pq.pop();
        }

        vector<int> ans;
        while(!pq.empty()) {
        	ans.push_back(pq.top().second);
        	pq.pop();
        }

        return ans;
    }
};
