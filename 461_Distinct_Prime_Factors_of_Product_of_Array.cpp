/*
Distinct_Prime_Factors_of_Product_of_Array.cpp

https://leetcode.com/contest/weekly-contest-326/problems/distinct-prime-factors-of-product-of-array/
*/

class Solution {
public:
	int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> us;

        for(int i=0; i<nums.size(); i++){
            int sqroot = (int) sqrt(nums[i]);

            for(int j=2; j <= sqroot; j++){
                if(nums[i] % j == 0){
                    us.insert(j);

                    while(nums[i]%j == 0){
                        nums[i] /= j;
                    }
                }
            }

            if(nums[i]>1){
                us.insert(nums[i]);
            }
        }

        return us.size();
    }
};