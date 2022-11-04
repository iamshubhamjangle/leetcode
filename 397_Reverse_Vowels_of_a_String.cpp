/*
Reverse_Vowels_of_a_String.cpp

https://leetcode.com/problems/reverse-vowels-of-a-string/
*/

class Solution {
public:
	// TC: O(2N) SC: O(N)
    string _reverseVowels(string s) {
        unordered_set<char> us = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        stack<char> st;
        int n = s.size();
        
        for(int i=0; i<n; i++) {
            if(us.find(s[i]) != us.end()) {
                st.push(s[i]);
            }
        }
        
        for(int i=0; i<n; i++) {
            if(us.find(s[i]) != us.end()) {
                s[i] = st.top(); st.pop();
            }
        }
        
        return s;
    }


    // TC: O(N) SC: O(1)
    string reverseVowels(string s) {
        unordered_set<char> us = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    	int n = s.size();

    	int i = 0;
    	int j = n-1;

    	while(i<j) {
    		if(us.find(s[i]) == us.end())
    			i++;
    		else if(us.find(s[j]) == us.end())
    			j--;
    		else{
    			swap(s[i], s[j]);
    			i++;
    			j--;
    		}
    	}

        return s;
    }
};