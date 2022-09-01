/*
Minimum_Amount_of_Time_to_Collect_Garbage.cpp

Input: garbage = ["G","P","GP","GG"], travel = [2,4,3]
Output: 21

Input: garbage = ["MMM","PGM","GP"], travel = [3,10]
Output: 37

Intuition
Observation 1:
"While one truck is driving or picking up garbage, the other two trucks cannot do anything."
We can simply sum up the total running time for each truck,
they don't affect each other.

Observation 2:
"Picking up one unit of any type of garbage takes 1 minute."
We don't care how many units for each type,
we only care the total amount.

Observation 3:
"however, they do not need to visit every house."
We only care the position of the last garbage for each type


Explanation
Firstly sum up the amount of gabages in total.
Second find up the last position for each type.
Calculate the prefix sum array of the travel distance.
Sum up the distance for each type of garbage.

Complexity
Time O(garbage + travel)
Space O(1)

https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int last[128] = {}, res = 0; // map of characters

        // Input: garbage = ["G","P","GP","GG"], travel = [2,4,3]
        // Output: 21
        for (int i = 0; i < garbage.size(); ++i) {
            res += garbage[i].size();
            for (char c : garbage[i])
                last[c] = i;
        }

        for (int j = 1; j < travel.size(); ++j)
            travel[j] += travel[j - 1];

        for (int c : "PGM")
            if (last[c])
                res += travel[last[c] - 1];

        return res;
    }
};

int main(){
	Solution s;
	vector<string> garbage;
	vector<int> travel;

	garbage = {"G","P","GP","GG"};
	travel = {2,4,3};
	cout << s.garbageCollection(garbage, travel) << endl;	
	garbage = {"MMM","PGM","GP"};
	travel = {3,10};
	cout << s.garbageCollection(garbage, travel) << endl;	
}