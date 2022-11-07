/*
Apply_Operations_to_an_Array.cpp

https://leetcode.com/contest/weekly-contest-318/problems/apply-operations-to-an-array/
*/

/*
Simply change the value of nums[i] to 2 times & set nums[i+1] to zero when nums[i] == nums[i+1].
Then take a pointer and keep on accumulating non zero value at the front.
Set all remaining values to zero, utill pointer is less then size of the array.
*/

class Solution {
public:
	// TC: O(N) SC: O(1)
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 0; i+1 < nums.size(); ++i){
            if(nums[i] == nums[i+1]){  //update values of ith and (i+1)th value
                nums[i] = 2*nums[i]; 
                nums[i+1] = 0;
            }
        }
        
        int i = 0;

        // collect all noon zero values at front
        for(auto n: nums) if(n != 0) nums[i++] = n;
    
        // set values to zero for remainintg ith element
        while(i < nums.size()) nums[i++] = 0;         
        
        return nums;
    }
};
