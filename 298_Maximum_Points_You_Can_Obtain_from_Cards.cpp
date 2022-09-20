/*
Maximum_Points_You_Can_Obtain_from_Cards.cpp

There are several cards arranged in a row, and each card has an associated number of points. 
The points are given in the integer array cardPoints.

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12

Input: cardPoints = [2,2,2], k = 2
Output: 4

https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/submissions/
prefix, suffix sum. TC: O(3N) SC: O(2N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// prefix, suffix sum. TC: O(3N) SC: O(2N)
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxScore = 0;

        // If we have to take all cards
        if(k == n) {
        	return accumulate(cardPoints.begin(), cardPoints.end(), 0);
       	}

       	// calculate prefix and suffix sums for O(1) access later looping
       	vector<int> prefix(n);
       	vector<int> suffix(n);

       	prefix[0] = cardPoints[0];
       	for(int i=1; i<n; i++) {
       		prefix[i] = prefix[i-1] + cardPoints[i];
       	}

       	suffix[n-1] = cardPoints[n-1];
       	for(int i=n-2; i>=0; i--) {
       		suffix[i] = suffix[i+1] + cardPoints[i];
       	}

       	// loop. 
       	// take 0 elements sum from first, k from last
       	// take 1 elements sum from first, k-1 from last
       	// go on...upto k and find maxScore.
       	for(int i=0; i<=k; i++) {
       		int score = 0;
       		if(i-1>=0) score += prefix[i-1];
       		if((n-k+i)<n) score += suffix[n-k+i];
       		maxScore = max(maxScore, score);
       	}

        return maxScore;
    }
};

// int main(){
// 	Solution s;
// 	vector<int> cardPoints;

// 	cardPoints = {1,2,3,4,5,6,1};
// 	cout << s.maxScore(cardPoints, 3) << endl;
	
// 	cardPoints = {2,2,2};
// 	cout << s.maxScore(cardPoints, 2) << endl;

// 	cardPoints = {9,7,7,9,7,7,9};
// 	cout << s.maxScore(cardPoints, 7) << endl;		
// }