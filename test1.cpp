#include <bits/stdc++.h>
using namespace std;

int arithmeticTriplets(vector<int>& nums, int diff) {
	int n = nums.size();
	int count = 0;

	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			for(int k=j+1; k<n; k++) {
				if(abs(nums[i] - nums[j]) == diff && abs(nums[k] - nums[j]) == diff)
					count++;
			}
		}
	}

	return count;
}

int main(){
	vector<int> nums = {0,1,4,6,7,10};
	cout << arithmeticTriplets(nums, 3) << endl;
	vector<int> nums2 = {4,5,6,7,8,9};
	cout << arithmeticTriplets(nums2, 2) << endl;
}
