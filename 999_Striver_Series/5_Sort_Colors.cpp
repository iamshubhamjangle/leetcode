/*
Sort_Colors.cpp

*/


class Solution {
public:
    // // 1. Sorting. TC: O(NlogN) SC: O(1)
    // void sortColors(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    // }


    // // 2. Counting the occurance. TC: O(N) SC: O(3)
    // void sortColors(vector<int>& nums) {
    //     vector<int> freq(3, 0);
    //     for(auto i: nums) {
    //         freq[i]++;
    //     }

    //     int i=0;
    //     for(int j=0; j<freq.size(); j++) {
    //         int loop = freq[j];
    //         while(loop--) {
    //             nums[i] = j; i++;
    //         }
    //     }
    // }


    // // 3. Using low, mid, high. TC: O(N) SC: O(1)
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return;

        int low = 0, mid = 0, high = n-1;

        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                mid++;  // mid will update as low will take mid
                low++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else if(nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--; // dont update mid as high wont consider it
            }
        }
    }
};