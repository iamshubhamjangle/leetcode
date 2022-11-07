/*
Maximum_69_Number.cpp

https://leetcode.com/problems/maximum-69-number/
*/

class Solution {
public:
	// Three Pass. TC: O(N) SC: O(1)
    int _maximum69Number (int num) {
    	// convert to string
        string s = to_string(num);

        // replace only the first 6 to 9
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '6') { 
            	s[i] = '9'; 
            	break; 
            }
        }

        // convert to int and return
        return stoi(s);
    }
    

    // One Pass. TC: O(N) SC: O(1)
    int maximum69Number (int num) {
		int i = 0;
		int temp = num;
		int first6idx = -1;

		// find the index of first 6
		while(temp > 0) {
			if(temp % 10 == 6) first6idx = i;	
			temp = temp / 10;
			i++;
		}

		// If we found an index add 3 to that position
		// else return num
		if(first6idx == -1) return num;
		return num + (3 * pow(10, first6idx));
    }
};