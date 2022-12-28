/*
Remove_Stones_to_Minimize_the_Total.cpp

https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/
*/

class Solution {
public:
	// Approach 1: Sorting k times. TC: O(KlogN) SC: O(1)


	// Approach 2: Min heap. TC: O(KlogN) SC: O(1)
    int minStoneSum(vector<int>& v, int k) {
        priority_queue<int> pq(v.begin(), v.end());  // max heap
        int res = accumulate(v.begin(), v.end(), 0)

        while(k--) {
            int temp = pq.top(); pq.pop();
            pq.push(temp - temp/2);
            res -= temp/2;
        }

        return res;
    }    
};