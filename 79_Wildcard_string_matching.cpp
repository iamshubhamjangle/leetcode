/*
Wildcard_string_matching.cpp

Given two strings wild and pattern where wild string may contain wild card characters and pattern string is a normal string. Determine if the two strings match. The following are the allowed wild card characters in first string :-

* --> Can be replaced by any sequence of characters, it can also be replaced by an empty string.
? --> Can be replaced by any one character.

Input : wild = ge*ks
        pattern = geeks
Output: Yes

Input : wild = ge?ks*
        pattern = geeksforgeeks
Output: Yes
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
	// Method 1: Two pointer - i for wild, j for pattern string. TC: O(N*M) - TLE, SC: O(N)
    bool match1(string w, string p) {
        int i=0;
        int j=0;
        int n=w.size();
        int m=p.size();
        string ans;

        while(i<n && j<m) {
        	// cout << "w[i]: " << w[i] << " p[j]: " << p[j];
        	if(w[i] == p[j]) {
        		ans.push_back(w[i]);
        		i++; j++;
        	}
        	else if(w[i] == '?') {
        		ans.push_back(p[j]);
        		i++; j++;
        	}
        	else if(w[i] == '*' && i==n-1) {
        		while(j<m) {
        			ans.push_back(p[j]);
        			j++;
        		}
        		i++;
        	}
        	else if(w[i] == '*') {
        		if(w[i+1] == p[j]) {
	        		ans.push_back(p[j]);
        			i+=2;
        			j++;
        		} else {
	        		ans.push_back(p[j]);
    	    		j++;
        		}
        	}

        	// cout << " ans: " << ans << endl;
        }

        if(w[i] == '?') return false;

        return p == ans;
    }

    bool match1(string w, string p) {
    	
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}