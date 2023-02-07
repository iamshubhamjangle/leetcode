/*
Fruit_Into_Baskets.cpp

https://leetcode.com/problems/fruit-into-baskets/
*/

class Solution {
public:
	// Brute. TC: O(N*N) SC: O(N)
    int _totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n <= 2) return n;

        int count = 0;
        
        for(int i=0; i<n-1; i++) {
            unordered_set<int> us;
            int cnt = 1;
            us.insert(fruits[i]);
            for(int j=i+1; j<n; j++) {
                us.insert(fruits[j]);
                if(us.size() > 2) break;
                cnt++;
                count = max(count, cnt);
            }
        }

        return count;
    }

    
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int left = 0, maxPicked = 0;
        
        for (int right = 0; right < fruits.size(); ++right) {
            basket[fruits[right]]++;
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0)
                    basket.erase(fruits[left]);
                left++;
            }
            
            maxPicked = max(maxPicked, right - left + 1);
        }
        
        return maxPicked;
    }
};