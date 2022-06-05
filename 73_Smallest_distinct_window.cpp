/*
Smallest_distinct_window.cpp

Given a string 's'. The task is to find the smallest window length that contains all the 
characters of the given string at least one time.
For eg. A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.

Input : "AABBBCBBAC"
Output : 3
Explanation : Sub-string -> "BAC"

Input : "aaab"
Output : 2
Explanation : Sub-string -> "ab"

Input : "GEEKSGEEKSFOR"
Output : 8
Explanation : Sub-string -> "GEEKSFOR"

https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1
	- Method 1: map unique element and iterate through each window TC: O(N*N*N). SC: O(N)
	- Method 2: Expand and contract window. O(N*N) SC: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    /*
		1.firstly expand the window until all the distinct characters of string 
		are not present in the window , once all the distinct characters are there simply 
		contract the window. 

		2.then in next iteration everytime we expand the window size by 1 and check
		if contraction is possible 

		3.after contracting the window size take min of all possible window sizes
    */

    int findSubString(string str) {
     int n = str.length();
       unordered_map<char,int> u;
       for(int i=0;i<n;i++){
           u[str[i]]=0;
       }
       int i=0,j=0,ans=INT_MAX,count=0;
       string res;
       while(j<n){
           if(u[str[j]]==0) count++;
           u[str[j]]+=1;
           
           if(count==u.size()){
               while(i<n && u[str[i]]>1){
                   u[str[i]]--;
                   i++;
               }
               if(ans > (j-i+1)){
                   ans = j-i+1;
                   res = str.substr(i,j-i+1);
               }
           }
           j++;
       }
       return res.size();
   }
	// Method 1: map unique element and iterate through each window TC: O(N*N*N). SC: O(N)
    // bool checkIfAllCharExist(string sub, int s) {
    // 	unordered_map<char, int> um;
    // 	for(char ch: sub)
    // 		um[ch] = 1;
    	
    // 	if(um.size() == s)
    // 		return true;

    // 	return false;
    // }

    // int findSubString(string str) {
    // 	int n = str.size();
    // 	if(n <= 1) return n;

    //     unordered_map<char, int> um;
    //     for(int i=0; i<n; i++) {
    //     	um[str[i]] = 1;
    //     }

    //     int windowSize = um.size();
    //     while(windowSize <= n) {
	   //      for(int i=0; i<n-windowSize+1; i++) {
	   //      	string sub = str.substr(i, windowSize);
	   //      	bool ans = checkIfAllCharExist(sub, um.size());
	   //      	if(ans) return windowSize;
	   //      }
	   //      windowSize++;
    //     }

    //     return -1;
    // }
};

int main() {
    int t;
    cin >> t;
    while (t--) { 
        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}