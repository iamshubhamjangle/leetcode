/*
Reverse_Words_in_a_String.cpp

https://leetcode.com/problems/reverse-words-in-a-string/
*/


class Solution {
public:
	// Stack. TC: O(N) SC: O(N)
    string _reverseWords(string s) {
        stack<string> st;
        string word = "";
        for(auto c: s) {
            if(c == ' ' && word.size() > 0) {
                st.push(word);
                word = "";
            } 
            else if(c != ' ') {
                word += c;
            }
        }
        
        if(word.size()) st.push(word);
        
        word = "";
        while(!st.empty()) {
            word += st.top(); st.pop();
            if(!st.empty()) word += " ";
        }
        
        return word;
    }


    // Replace Multi-Spaces with single space
	//Space Complexity = O(1)
    string reverseWords(string s) {
        
        while(s[0] == ' ') s.erase(0, 1); //Remove spaces from the beginning
        while(s[s.size()-1]==' ') s.erase(s.size()-1); //Remove spaces from the ending
        
        int i = 0, space_count = 0;
		/*Now we count the middle spaces between two words, if more than one space
		found between two words, then remove it*/
        while(s[i])
        {
		
		   /*if the character is not space, then this is the starting of a new word. 
		   So, make the space count 0.*/
		   
            if(s[i] == ' ') space_count++;
            else space_count = 0; 
            if(space_count > 1) //more than one space found
            {
                s.erase(i,1);
                continue;
            }
            i++;
        }
        reverse(s.begin(),s.end());
        int left = 0;
        for(i=1;i<s.size();i++)
        {
            if(s[i] == ' ') // space found means we have a word in our left and we have to reverse it
            {
                reverse(s.begin()+left, s.begin()+i);
                left = i+1;
            }
            else if(i == s.size()-1)
            {
                reverse(s.begin()+left, s.begin()+i+1);
            }
        }
        return s;
    }
};