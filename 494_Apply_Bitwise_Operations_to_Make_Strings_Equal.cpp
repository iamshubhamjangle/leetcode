/*
Apply_Bitwise_Operations_to_Make_Strings_Equal.cpp

- All 0 string can not change.
- Any other strings can transform from each other.

So we only need to check
- if s has 1.
- if target has 1.

https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal
*/

// TC: O(N) SC: O(1)
class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        return (s.find('1') != string::npos) == (t.find('1') != string::npos);
    }
};