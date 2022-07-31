#include <bits/stdc++.h>
using namespace std;

int minimumOperations(vector<int>& nums) {
	int n = nums.size();
	int count = 0;
	sort(nums.begin(), nums.end());

	for(int i=0; i<n; i++) {
		while(i<n && nums[i] == 0) i++;

		if(i ==n) break;

		int sm = nums[i];
		for(int j=0; j<n; j++) {
			if(nums[j] != 0) nums[j] -= sm;
		}

		count++;
		sort(nums.begin(), nums.end());
	}

	return count;
}

int main(){
	vector<int> nums = {1,5,0,3,5};
	cout << minimumOperations(nums) << endl;
	vector<int> nums1 = {0};
	cout << minimumOperations(nums1) << endl;
	vector<int> nums2 = {10};
	cout << minimumOperations(nums2) << endl;
}
