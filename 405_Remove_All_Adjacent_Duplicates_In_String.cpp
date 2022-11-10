/*
Remove_All_Adjacent_Duplicates_In_String.cpp

https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
*/

class Solution {
public:
    // TC: O(N) SC: O(N)
    string removeDuplicates(string S) {
        string res = "";
        for (char& c : S)
            if (res.size() && c == res.back())
                res.pop_back();
            else
                res.push_back(c);
        return res;
    }
};