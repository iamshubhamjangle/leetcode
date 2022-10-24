/*
Maximum_Length_of_a_Concatenated_String_with_Unique_Characters.cpp

https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
*/

// class Solution {
// public:
//     int maxUniqueChar(string s) {  // CHECKER FUNCTION
//         int count[26] = {0};
//         for(int i = 0; i < s.size(); i++)
//             if(count[s[i] - 'a']++ > 0) return 0;
//         return s.size();
//     }
    
//     void solve(vector<string> &arr, int index, string curr, int &ans) {
//         if(index == arr.size()) {            // BASE CONDITION
//             if(maxUniqueChar(curr) > ans) {
//             ans = curr.size();
//             }
//             return;
//         }
//         solve(arr, index+1, curr, ans); 
//         solve(arr, index+1, curr+arr[index], ans);
//     }
    
//     int maxLength(vector<string> &arr) {
//         int ans = 0;
//         solve(arr, 0, "", ans);
//         return ans;
//     }
// };


// DFS
class Solution {
public:
    int maxLength(vector<string>& arr, string str = "", int index = 0) {
	    //Use set to check if the string contains all unique characters
        unordered_set<char>s(str.begin(), str.end());
        if (s.size() != ((int)str.length())) 
            return 0;
        
        int ret = str.length();
        for (int i = index; i < arr.size(); i++)
            ret = max(ret, maxLength(arr, str+arr[i], i+1));

        return ret;
    }
};