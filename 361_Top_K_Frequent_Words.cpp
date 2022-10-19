/*
Top_K_Frequent_Words.cpp

https://leetcode.com/problems/top-k-frequent-words/
*/

// 1. Map of frequency, put it in vector sort by desc freq, get the top k elements
// TC: O(NlogN) SC: O(2N)

// 2. Use priority queue. min heap.
// TC: O() SC: O(N)

typedef pair<int, string> pis;

struct cmp {
	bool operator()(pis &a, pis &b) {
		if(a.first > b.first) return true;	// min freq must be at top
		if(a.first == b.first && a.second < b.second) return true;  // bigger char must be at top as we will reverse the result vector
		return false;	// no swap	
	}
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for(auto &w: words) freq[w]++;
        
        priority_queue<pis, vector<pis>, cmp> pq;
        for(auto [a, b]: freq) {
            pq.push({b, a});				// pq.push({freq, string})
            if(pq.size() > k) pq.pop();
        }
        
        vector<string> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second); 
            pq.pop();            
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};