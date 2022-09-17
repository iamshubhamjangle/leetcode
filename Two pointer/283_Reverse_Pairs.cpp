/*
Reverse_Pairs.cpp

Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 5 > 2 * 1

https://leetcode.com/problems/reverse-pairs/
*/


class Solution {
public:
	int merge(vector<int> &nums, int low, int mid, int high) {
		int count = 0;
		int j = mid + 1;
		for(int i=low; i<=mid; i++) {
			while(j <= high && nums[i] > 2LL * nums[j]) {
				j++;
			}
			count += (j - (mid+1));
		}

		vector<int> temp;
		int left = low, right = mid+1;
		while(left <= mid && right <= high) {
			if(nums[left] <= nums[right]) {
				temp.push_back(nums[left++]);
			} else {
				temp.push_back(nums[right++]);
			}
		}

		while(left <= mid) {
			temp.push_back(nums[left++]);
		}

		while(right <= high) {
			temp.push_back(nums[right++]);
		}

		for(int i=low; i<=high; i++) {
			nums[i] = temp[i - low];
		}

		return count;
	}

	int mergeSort(vector<int> &nums, int low, int high) {
		if(low >= high) return 0;
		int mid = (low + high) / 2;
		int l = mergeSort(nums, low, mid);
		int r = mergeSort(nums, mid+1, high);

		int count = l + r + merge(nums, low, mid, high);
		return count;
	}

    int reversePairs(vector<int>& nums) {
    	int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};

