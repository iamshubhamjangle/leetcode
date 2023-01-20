/*
3Sum.cpp

https://leetcode.com/problems/3sum/description/
*/


class Solution {
public:
	/*
		Sort and two pointer. Use set to avoid duplicates
		TC: O(N*N) SC: O(N)
	*/
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return {};    // triplets cannot be formed

        sort(nums.begin(), nums.end());
        set<vector<int>> us;

        for(int i=0; i<n-2; i++) {
            if(nums[i] > 0) break; // We wont find b,c < 0 further as array is Sorted
            int b = i+1;
            int c = n-1;
            while(b < c) {
                int sumOfNums = nums[i] + nums[b] + nums[c];
                if(sumOfNums > 0)
                    c--;
                else if(sumOfNums < 0)
                    b++;
                else {
                    us.insert({nums[i], nums[b], nums[c]});
                    b++; c--;
                }
            }
        }

        vector<vector<int>> res;
        for(auto &v: us) {
            res.push_back(v);
        }
        return res;
    }


	/*
		Sort and two pointer. Ignore duplicates for a,b,c by doing b++, c--
		TC: O(N*N) SC: O(1)
	*/
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return {};    // triplets cannot be formed

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i=0; i<n-2; i++) {
            if(nums[i] > 0) break; // We wont find b,c < 0 further as array is Sorted
            
            if(i>0 && nums[i] == nums[i-1]) continue;	// if nums[a] is same as previous to avoid duplicates

            int b = i+1;
            int c = n-1;

            while(b < c) {
                int sumOfNums = nums[i] + nums[b] + nums[c];
                if(sumOfNums > 0)
                    c--;
                else if(sumOfNums < 0)
                    b++;
                else {
                    cout << "sum 0 = " << nums[i] << ", " << nums[b] << ", " << nums[c] << endl;
                    res.push_back({nums[i], nums[b], nums[c]});
                    int prevB = nums[b];
                    int prevC = nums[c];
                    while(b<c && nums[b] == prevB) b++;
                    while(b<c && nums[c] == prevC) c--;
                }
            }
        }

        return res;
    }
};