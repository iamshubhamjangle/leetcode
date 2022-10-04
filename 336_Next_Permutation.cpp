/*
Next_Permutation.cpp

https://leetcode.com/problems/next-permutation/
*/

// class Solution {
// public:
// 	// 1. Using next_permutation function in cpp
//     // TC: O(n) SC: O(1)
//     void nextPermutation(vector<int>& nums) {
//         next_permutation(nums.begin(), nums.end());
//     }
// };


// 2. Find all the possible permuation store it in set, find the next permutation from it.
// TC: O(n*n!) SC: O(N)



// 3. 
// find a[i] < a[i+1]. idx1 = i
// find a[i] > a[idx1]. idx2 = i
// swap(a[idx1], a[idx2])
// reverse(idx1 + 1, last)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int idx1 = -1, idx2 = -1;
		int n = nums.size();
    	for(int i=n-2; i>=0; i--) {
    		if(nums[i] < nums[i+1]) {
    			idx1 = i; break;
    		}
    	}


    	if(idx1 < 0) {
    		reverse(nums.begin(), nums.end());
    	} else {
	    	for(int i=n-1; i>=0; i--) {
	    		if(nums[i] > nums[idx1]) {
                    idx2 = i;
                    break;
                }
	    	}

	    	swap(nums[idx1], nums[idx2]);

	    	reverse(nums.begin() + idx1 + 1, nums.end());
    	}
    }
};










class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int N = arr.size();
        int i = N - 1;
        while(i > 0 && arr[i] <= arr[i - 1]){
            i--;
        }
        reverse(arr.begin() + i, arr.end());
        int l = i - 1, r = i;
        while(l >= 0 && r < N){
            if(arr[r] > arr[l]){
                swap(arr[l], arr[r]);
                break;
            }
            r++;
        }
    }
};

