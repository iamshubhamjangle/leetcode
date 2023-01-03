class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Method 0: next_permutation()
        // next_permutation(nums.begin(), nums.end());

        // Method 1: Generate all possible combinations.


        // Method 2: Looking at the pattern
        int n = nums.size();
        int i = 0;

        for(i=n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) break;
        }

        if(i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int j;
        for(j=n-1; j>=0; j--) {
            if(nums[j] > nums[i]) {
                break;
            }
        }

        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
        
    }
};