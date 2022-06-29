/* 
Find_all_Characters_in_String2_not_present_String1.cpp

Print all the chars in str2 not in str1
	- followup: keep the order same.

Input:
str1: abcdefgh
str2: mnopabcd
Output: mnop

https://www.geeksforgeeks.org/find-all-characters-in-given-string-which-are-not-present-in-other-string/
	- Bruteforce: TC: O(N*M). SC: O(N) 
	- Method 2: Using unordered map TC: O(N) SC: O(N)
	- Custom hash function TC: O(N) SC: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

// Bruteforce: TC: O(N*M). SC: O(N) 
vector<char> findTheDifference1(string str1, string str2) {
	int m = str1.size();
	int n = str2.size();
	vector<char> ans;
	for(int i=0; i<n; i++) {
		bool found = false;
		for(int j=0; j<m; j++) {
			if(str1[j] == str2[i]) {
				found = true;
			}
		}
		if(!found)
			ans.push_back(str2[i]);
	}
	return ans;
}
 
// Method 2: Using unordered map TC: O(N) SC: O(N)
vector<char> findTheDifference2(string str1, string str2) {
	// map<char, int> um;			// map (ordered) -> O(logN)	-> Self balancing BST
	unordered_map<char, int> um;	// un-map		 -> O(1)	- best, O(N) - worst	-> Hash tables
	int m = str1.size();
	int n = str2.size();

	for(int i=0; i<n; i++) {
		um[str2[i]] = 1;
	}

	for(int i=0; i<m; i++) {
		if(um[str1[i]])
			um[str1[i]]++;
	}

	vector<char> ans;
	for(auto i: um) {
		if(i.second == 1)
			ans.push_back(i.first);
	}

	return ans;
}

// Method 3: 
/* Custom hash function return addr for each 26 char's
** 
*/
int hashFunction(char c) {
	return c - 'a';
}

vector<char> findTheDifference(string str1, string str2) {
	int arr[26] = {};
	int m = str1.size();
	int n = str2.size();

	for(int i=0; i<n; i++) {
		arr[hashFunction(str2[i])] = 1;		// um[str2[i]] = 1;
	}

	for(int i=0; i<m; i++) {
		if(arr[hashFunction(str1[i])] > 0)
			arr[hashFunction(str1[i])]++;
	}

	vector<char> ans;
	for(int i=0; i<26; i++) {
		if(arr[i] == 1)
			ans.push_back(i + 'a');
	}

	return ans;
}

int main() {
    string str1 = "abcdefgh";
    string str2 = "mnopabcd";
 
    vector<char> ans = findTheDifference(str1, str2);
 
    for (char c : ans)
        cout << c << " ";
    return 0;
}