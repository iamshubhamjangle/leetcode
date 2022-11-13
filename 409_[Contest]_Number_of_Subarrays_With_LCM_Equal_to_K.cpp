/*
[Contest]_Number_of_Subarrays_With_LCM_Equal_to_K.cpp

*/

class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        unsigned int n = nums.size();
        unsigned int cnt = 0;
        
        for(int i=0; i<n; i++) {
            unsigned int temp = nums[i];
            for(int j=i; j<n; j++) {
                temp = lcm(temp, nums[j]);
                if(temp == k)
                    cnt++;
            }
        }
        
        return cnt;
    }
    
};