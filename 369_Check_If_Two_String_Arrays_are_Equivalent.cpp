/*
Check_If_Two_String_Arrays_are_Equivalent.cpp

https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
*/

class Solution {
public:
// // Method 1: Loop and push to new string. TC: O(N+M) SC: O(N+M)
//     bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
//         string s1, s2;
        
//         for(auto w: word1) {
//             for(auto c: w) {
//                 s1.push_back(c);
//             }
//         }
        
//         for(auto w: word2) {
//             for(auto c: w) {
//                 s2.push_back(c);
//             }
//         }
        
//         return s1 == s2;
//     }
    
// // Method 2: String concat. TC: O(N+M) SC: O(N+M)
//     bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
//         string s1, s2;
        
//         for(auto w: word1) {
//             s1 += w;
//         }
        
//         for(auto w: word2) {
//             s2 += w;
//         }
        
//         return s1 == s2;
//     }
    
    // Method 3: Constant Space two pointer. TC: O(N+M) SC: O(1)
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0; // word pointers
        int m = 0, n = 0; // char pointers
        
        while (i < word1.size() and j < word2.size()) {            
            if (word1[i][m++] != word2[j][n++])
                return false;
            
            if (m >= word1[i].size())
                i++, m = 0;
            
            if (n >= word2[j].size())
                j++, n = 0;
        }
        
        return i == word1.size() and j == word2.size();
    }    
};