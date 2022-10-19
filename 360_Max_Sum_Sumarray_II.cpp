/*
Max_Sum_Sumarray_II.cpp

Return the max Sum Subarray.
*/

#include <bits/stdc++.h>
using namespace std;

// Print Vector int:
void print(vector<int> &v) {
	for(auto i: v) cout << i << ", ";
	cout << endl;
}

void maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN;
    int sum = 0;
    int startIndex = 0;
    int endIndex = 0;

    for(int i=0; i<nums.size(); i++) {
    	sum += nums[i];
    	endIndex = i;

    	if(sum > maxSum) {
    		maxSum = sum;
    		endIndex = i;
    	}

    	if(sum < 0) {
    		startIndex = i;
    		sum = 0;
    	}
    }

    for(int i=startIndex; i<=endIndex; i++) {
    	cout << nums[i] << " ";
    }
    cout << endl;
    cout << "maxSum: " << maxSum << endl;
}

int main(){
	vector<int> nums;

	nums = {-2,1,-3,4,-1,2,1,-5,4};
	maxSubArray(nums);

	return 0;
}