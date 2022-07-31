/*
House_Robber_II.cpp

Input:
3
1
0
3
2 3 2
4
1 3 2 1

Output:
0
3
4

https://www.codingninjas.com/codestudio/problems/house-robber_839733
Method. take notake. as we dont want adjacent (first and last). take arr (0 to n-2) and (1 to n-1)
1. Recursion	 : TC: O(2^n) SC: O(1) ASC: O(N)
2. Memoization: TC: O(N) SC: O(N) ASC: O(N)
3. Tabulation : TC: O(N) SC: O(N)
4. SpaceOptimized: TC: O(N) SC: O(N)
*/

#include <bits/stdc++.h>
using namespace std;



// long long int solve(int i, vector<int> &arr) {
//     if(i == 0) return arr[0];        // Money in first house
//     if(i < 0) return 0;
        
//     int take = solve(i-2, arr) + arr[i];
//     int notake = solve(i-1, arr) + 0;
    
//     return max(take, notake);
// }

// long long int houseRobber(vector<int>& valueInHouse) {
//     int n = valueInHouse.size();
//     return solve(n, valueInHouse);
// }


// Space optimization - Method 2: Topdown.
long long int solve(vector<int> &nums){
    int n = nums.size();

    long long int prev1 = 0;
    long long int prev2 = nums[0];

    for(int i=1; i<n; i++) {
    	long long int take = nums[i];
    	if(i > 1) take += prev1;

    	long long int notake = prev2 + 0;
    	long long int ans = max(take, notake);

    	prev1 = prev2;
    	prev2 = ans;
    }

    return prev2;
}

long long int houseRobber(vector<int>& valueInHouse) {
    int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];

    vector<int> temp1;
    vector<int> temp2;

    for(int i=0; i<n; i++) {
    	if(i != 0) temp1.push_back(valueInHouse[i]);
    	if(i != n-1) temp2.push_back(valueInHouse[i]);
    }

    return max(solve(temp1), solve(temp2));
}


int main(){
	int t;
	cin >> t;		//input no. of test cases
	while(t--){
		int n; cin >> n;
		vector<int> v;
		for(int i=0; i<n; i++) {
			int temp; cin >> temp;
			v.push_back(temp);
		}
		cout << houseRobber(v) << endl;	//run this 't' times
	}
}
