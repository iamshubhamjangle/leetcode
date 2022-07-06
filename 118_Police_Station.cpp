/*
Police_Station.cpp

Thief lives in Linear Land where everything exists on a single-dimensional axis.
There are N police stations in the city. The ith police station is located at coordinate x[i]. Geek lives at coordinate a. Distance between Geek and ith police station is given by |a - x[i]|.

Thief wants to choose two distinct police stations such that the sum of the distance between the first police station and his house, and the distance between 2nd police station and his house is the maximum possible.

More formally return the maximum value of the expression |a - x[i]| + |a - x[j]| for two distinct valid indexes i and j
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int solve(int n, int a, vector<int> x) {
    // 	int ans = 0;
    //     for(int i=0; i<n; i++) {
    //     	for(int j=i+1; j<n; j++) {
    //     		int cal = abs(a - x[i]) + abs(a - x[j]);
    //     		ans = max(cal ,ans);
    //     	}
    //     }
    //     return ans;
    // }

    int solve(int n, int a, vector<int> x) {
    	priority_queue<int> pq;
    	for(auto i: x)
    		pq.push(abs(i - a));

    	int first = pq.top();
    	pq.pop();
    	int second = pq.top();

		return first+second;
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {

        int N, a;
        cin >> N >> a;


        vector<int> x(N);
        for (int i = 0; i < N; i++)
            cin >> x[i];

        Solution ob;
        cout << ob.solve(N, a, x) << "\n";
    }
    return 0;
}