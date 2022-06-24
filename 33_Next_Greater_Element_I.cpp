/*
Next_Greater_Element_I.cpp
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]

https://leetcode.com/problems/next-greater-element-i/description/
	- Bruteforce: TC: O(N*N), SC: O(N)
	- Method 2: Use stack and umap. TC: O(N), SC: O(N)

*/

#include <bits/stdc++.h>
using namespace std;

// Bruteforce: TC: O(N*N), SC: O(N)
// - for each element in num1 check at what index it is present
// - iterate from that index to n-1 and find next greater element
// - if exist push to array or else push -1
// vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
// 	int n = nums1.size();
// 	int m = nums2.size();
// 	vector<int> ans;
// 	for(int i=0; i<n; i++) {
// 		int indexFound = -1;
// 		bool nextGreaterFound = false;

// 		for(int j=0; j<m; j++) {
// 			if(nums2[j] == nums1[i]) {
// 				indexFound = j;
// 				break;
// 			};
// 		}
		
// 		for(int j=indexFound+1; j<m; j++) {
// 			if(nums2[j] > nums1[i]) {
// 				ans.push_back(nums2[j]);
// 				nextGreaterFound = true;
// 				break;
// 			}
// 		}

// 		if(!nextGreaterFound) {
// 			ans.push_back(-1);
// 		};
// 	}

// 	return ans;
// }

// Method 2: Use stack and umap. TC: O(N), SC: O(N)
// Step1: FINDING ALL THE NEXT GREATER ELEMENTS IN A MAP 
/*	Iterate through num2 array. if(stack is empty) push curr to stack
	Find if next greater exist for current element.
	if it exist push prev (key) and current (value) element to map.
	push current to stack */
// Step2: Iterate through nums1, if NGE exist in umap push its value in vector
	// if doesnt exist push -1 to vector
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s;
        vector<int> ans(size(T));
        for(int cur = 0; cur < size(T); cur++) {
            while(size(s) and T[cur] > T[s.top()]) {    // pop till current temp < stack's top's temp. This maintains monotonic stack
                ans[s.top()] = cur - s.top();           // cur day will be next warmer day for each element that's popped
                s.pop();
            }
            s.push(cur);                                // push onto stack to find next warmer day for cur later on
        }
        return ans;
    }
}

void solve();

int main(){
	int t;
	cin >> t;		//input no. of test cases
	while(t--){
		solve();	//run this 't' times
	}
}

void solve() {
	int n, m, temp;
	vector<int> arr1, arr2;

	cin >> n;

	for(int i=0; i<n; i++) {
		cin >> temp;
		arr1.push_back(temp);
	}

	cin >> m;
	for(int i=0; i<m; i++) {
		cin >> temp;
		arr2.push_back(temp);
	}

	vector<int> ans = nextGreaterElement(arr1, arr2);
	for(auto i: ans) cout << i << " ";
}
