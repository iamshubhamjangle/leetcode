/*
K_Closest_Points_to_Origin.cpp

Given an array of points where points[i] = [xi, yi] represents a point on the 
X-Y plane and an integer k, return the k closest points to the origin (0, 0).

Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]

https://leetcode.com/problems/k-closest-points-to-origin/
*/

// 
// Distance b/w two points 	= sqrt(sq(x2-x1) + sq(y2-y1))
// As point 1 is origin. 	= sqrt(sq(x2) + sq(y2))
// 

#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x;
	int y;
	double distance;
};

bool comp(struct Point a, Point b) {
	if(a.distance < b.distance) return true;	// noswap
	return false;
}

class Solution {
public:
	// 1. Sort - TC: O(N + NlogN), SC: O(N)
    // vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // 	int n = points.size();

    //     vector<vector<int>> ans;		// store k closest points
    //     vector<struct Point> v;			// coordinates, distance

    //     for(auto i: points) {
    //     	double distance = sqrt((i[0] * i[0]) + (i[1] * i[1]));
    //     	v.push_back({i[0], i[1], distance});
    //     }

    //     sort(v.begin(), v.end(), comp);

    //     for(int i=0; i<k; i++) ans.push_back({v[i].x, v[i].y});

    //     return ans;
    // }


	// // 2. Heap - TC: O(NlogK), SC: O(N)
 //    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
 //        vector<vector<int>> ans;						// store k closest points
 //    	if(points.empty()) return ans;

 //    	priority_queue<pair<double, pair<int,int>>> pq;	// max Heap = {distance, {x,y}}

 //        for(auto i: points) {
 //        	double distance = sqrt((i[0] * i[0]) + (i[1] * i[1]));
 //        	pq.push({distance, {i[0], i[1]}});
 //        	if(pq.size() > k) pq.pop();
 //        }

 //        while(!pq.empty()) {
 //        	ans.push_back({pq.top().second.first, pq.top().second.second});
 //        	pq.pop();
 //        }

 //        return ans;
 //    }



	// // 3. Heap - TC: O(NlogK), SC: O(N)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;						// store k closest points
    	if(points.empty()) return ans;

    	priority_queue<pair<int, pair<int,int>>> pq;	// max Heap = {distance, {x,y}}

        for(auto i: points) {
        	int distance = (i[0] * i[0]) + (i[1] * i[1]);	// Even if we dont take sqrt sorted answer will be in same order 
        	pq.push({distance, {i[0], i[1]}});
        	if(pq.size() > k) pq.pop();
        }

        while(!pq.empty()) {
        	ans.push_back({pq.top().second.first, pq.top().second.second});
        	pq.pop();
        }

        return ans;
    }
};








// ---------------------------Runner-------------------------------- //

void print(vector<vector<int>> &v) {
	cout << "[";
	for(auto i: v) { cout << "["; for(auto j: i) cout << j << ","; cout << "]"; }
	cout << "]" << endl;
}

int main(){
	Solution s;
	vector<vector<int>> points;
	vector<vector<int>> ans;

	points = {{1,3}, {-2,2}};
	ans = s.kClosest(points, 1);
	print(ans);

	points = {{-5,4},{-6,-5},{4,6}};
	ans = s.kClosest(points, 2);
	print(ans);
}


