/*
[Contest]_Move_Pieces_to_Obtain_a_String.cpp
https://leetcode.com/problems/move-pieces-to-obtain-a-string/
Method: Normal loops - very tricky
*/

class Solution {
public:
    bool canChange(string st, string tar) {
        int n=tar.length(),m=st.length();
        if(n!=m) return false;
    
        int i=0,j=0;
        while(i<n || j<n){
            
            while(i<n && tar[i]=='_') i++;
            while(j<n && st[j]=='_') j++;
            
            // If all char of st & tar = _ return true else false if any one is _;
            if(i==n || j==n) return i==n && j==n;
            
            // after ignoring all _ if first char are not equal return false
            if(tar[i]!=st[j]) return false; 
            
            if(tar[i]=='L'){
                if(j<i) return false;
            }
            else{
                if(i<j) return false;
            }
            
            i++;
            j++;
        }
        return i==n && j==n;
    }
};