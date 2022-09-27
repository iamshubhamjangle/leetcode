/*
Sort_Array_by_Increasing_Frequency.cpp

Given an array of integers nums, sort the array in increasing order based on the 
frequency of the values. If multiple values have the same frequency, sort them in decreasing order.
Return the sorted array.

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]

https://leetcode.com/problems/sort-array-by-increasing-frequency/
*/


// // 1. Map and sort. TC: (3N + NlogN) SC: O(2N)
// typedef pair<int,int> pii;
// bool comparator(pii a, pii b) {
// 	if(a.second < b.second) return true;	// noswap
// 	else if(a.second > b.second) return false;	// swap
// 	else if(a.first > b.first) return true;
// 	return false;
// }

// class Solution {
// public:
//     vector<int> frequencySort(vector<int>& nums) {
//         int n = nums.size();

//         // create frequency map
//         unordered_map<int, int> freq;
//         for(auto i: nums) freq[i]++;

//         // create a vector from freq map
//         vector<pii> v;	// value, freq
//     	for(auto i: nums) v.push_back({i, freq[i]});

//     	sort(v.begin(), v.end(), comparator);

//     	vector<int> ans;
//     	for(auto i: v) ans.push_back(i.first);
//     	return ans;
//     }
// };



// 2. Map and Heap. TC: (N + NlogK) SC: O(2N)
typedef pair<int,int> pii;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        priority_queue<pii> pq;	// max heap - as we need min heap we multi freq by -1
        for(auto it : mp){
            pq.push({-it.second,it.first});
        }

        vector<int> result;
        while(!pq.empty()){
            int x = pq.top().first;
            for(int i=0;i<abs(x);i++){
                result.push_back(pq.top().second);
            }
            pq.pop();
        }
        return result;
    }
};