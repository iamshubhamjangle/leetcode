/*
[Contest]_Maximum_Matching_of_Players_With_Trainers.cpp

Return the maximum number of matchings between players and trainers that satisfy these conditions.

Input: players = [4,7,9], trainers = [8,2,5,8]
Output: 2

Input: players = [1,1,1], trainers = [10]
Output: 1

https://leetcode.com/problems/maximum-matching-of-players-with-trainers/
*/

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(trainers.begin(), trainers.end());
        sort(players.begin(), players.end());
        
        int n = players.size();
        int m = trainers.size();
        
        if(n == 0 || m == 0) return 0;
        
        int i = 0;
        int j = 0;
        int count = 0;
        
        while(i < n && j < m) {
            if(players[i] <= trainers[j]) {
                count++;
                i++;
                j++;
            } else if(players[i] > trainers[j]) {
                j++;
            }
        }
        
        return count;
    }
};