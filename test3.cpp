/*
Check_if_There_is_a_Valid_Partition_For_The_Array.cpp

Example 1:
Input: nums = [4,4,4,5,6]
Output: true
Explanation: The array can be partitioned into the subarrays [4,4] and [4,5,6]. This partition is valid, so we return true.

Example 2:
Input: nums = [1,1,1,2]
Output: false
Explanation: There is no valid partition for this array.

https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/

*/

#include <bits/stdc++.h>
using namespace std;

/*
Three cases :
check for 2 consicutive are equal
check for 3 consicutive are equal
check for 3 increasing numbers
*/
bool solve(vector<int>& nums, int i){
    if(i == nums.size()) return true;
    if(i > nums.size()) return false;
    
    if(i + 1 < nums.size() && nums[i] == nums[i+1] ) {
        if(solve(nums, i + 2)) return true;
        if(i + 2 < nums.size() && nums[i] == nums[i+2]){
            if(solve(nums, i + 3)) return true;
        }
    }
    if(i + 2 < nums.size() && nums[i] == nums[i+1]-1 && nums[i] == nums[i+2] - 2 ){
        if(solve(nums, i + 3)) return true;
    }
    return false;
}

bool validPartition(vector<int>& nums) {
    if(nums.size() == 2 ) return nums[0] == nums[1];
    return solve(nums, 0);
}

int main(){
	vector<int> nums1 = {4,4,4,5,6};
	cout << validPartition(nums1) << endl;

	vector<int> nums2 = {1,1,1,2};
	cout << validPartition(nums2) << endl;
}