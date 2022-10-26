/*
Majority_Element_II.cpp

*/

class Solution {
public:
// Method 1: Pick a element and check if it occurs more than n/3 times. TC: O(N*N) SC: O(1)

// // Method 2: Store the frequency. TC: O(N) SC: O(N)
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans;
        
//         unordered_map<int, int> um;
//         for(auto &num: nums) um[num]++;
        
//         for(auto &i: um) {
//             if(i.second > n/3) ans.push_back(i.first);
//         }
        
//         return ans;
//     }



// Method 3: Boyer Moore Voting Algo. TC: O(N) SC: O(1)
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int num1 = -1;
        int num2 = -1;
        int c1 = 0;
        int c2 = 0;

        // As at max there can be two majority element considering n/3 condition
        // we will be tracking the counts of the majority element
        for(auto &curr: nums) {
            if(curr == num1) 
                c1++;
            else if(curr == num2) 
                c2++;
            else if(c1 == 0) {
                num1 = curr;
                c1++;
            }
            else if(c2 == 0) {
                num2 = curr;
                c2++;
            }
            else {
                c1--;
                c2--;
            }
        }

        // counting the occurance of num1, num2
        // If they are beyond n/3 consider them
        c1 = 0;
        c2 = 0;
        vector<int> ans;
        for(auto &curr: nums) {
            if(curr == num1) c1++;
            else if(curr == num2) c2++;
        }

        if(c1 > n/3)
            ans.push_back(num1);
        if(c2 > n/3)
            ans.push_back(num2);

        return ans;
    }

};