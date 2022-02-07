#include <bits/stdc++.h>
using namespace std;
vector<int> ans;

int main(){
	vector<string> strs = {"doooog","dooacecar","dooooooogcar"};

	//Finding the shortest string
	int size = INT_MAX;
	string shortestString = "";

	for(string s: strs) {
		if(s.size() < size) {
			size = s.size();
			shortestString = s;
		}
	}

	// vector<string> strs = {"flower","flow","flight"};
	// stack st = {f,l,o,w}
	for(int i=0; i<strs.size(); i++) {
		for(int j=0; j<shortestString.size(); j++) {
			if(strs[i][j] != shortestString[j]) {
				shortestString = shortestString.substr(0,j);
				break;
			}
		}
	}

	cout << shortestString;
}