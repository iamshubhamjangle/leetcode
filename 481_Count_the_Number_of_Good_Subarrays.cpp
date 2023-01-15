/*
Count_the_Number_of_Good_Subarrays.cpp

2537. https://leetcode.com/problems/count-the-number-of-good-subarrays/submissions/878754143/

more sliding window problems: https://leetcode.com/problems/count-the-number-of-good-subarrays/solutions/3052559/java-c-python-sliding-window/?orderBy=most_votes
*/

class Solution {
public:
    long long countGood(vector<int>& A, int k) {
        long long res = 0;
        unordered_map<int, int> count;
        for (int i = 0, j = 0; j < A.size(); ++j) {
            k -= count[A[j]]++;
            while (k <= 0)
                k += --count[A[i++]];
            res += i;
        }
        return res;
    }
};