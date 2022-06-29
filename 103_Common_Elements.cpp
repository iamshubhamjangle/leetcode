/*
Common_Elements.cpp

Given two lists V1 and V2 of sizes n and m respectively. 
Return the list of elements common to both the lists and 
return the list in sorted order. Duplicates may be there in the output list.

Input:
n = 5, v1[] = {3, 4, 2, 2, 4}	= [2 2 2 3 4 4]
m = 4, v2[] = {3, 2, 2, 7}		= [2 2 3 7]
Output:
2 2 3

https://practice.geeksforgeeks.org/problems/common-elements5420/1
Method 1: Bruteforce. TC: O(M*N) SC: O(N)
- iterate through v1
- for each element, check if same element exist in v2
- if exist add it answer -> replace the element in v2 with INT_MIN
- sort answer

Method 2: Sorting. TC: O(NlogN) SC: O(N)
- Sort both the arrays
- Two pointers while(a<n && b<m)
- if match add to ans or else if v1[a] < v2[b] a++; else b++;

Method 3: Sort and Binary Search. TC: O(NlogN) SC: O(N)
- Sort V2 and loop v1 with binary search on V2

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
	// Method 1: Bruteforce. TC: O(M*N) SC: O(N)
    vector<int> common_element1(vector<int>v1,vector<int>v2) {
        vector<int> ans;
        int n = v1.size();
        int m = v2.size();
        for(int i=0; i<n; i++) {			//N*M
        	for(int j=0; j<m; j++) {
        		if(v1[i] == v2[j]) {
        			ans.push_back(v1[i]);
        			v1[i] = INT_MIN;
        			break;
        		}
        	}
        }

        sort(ans.begin(), ans.end());		//NlogN
        return ans;
    }


	// Method 2: Sorting both array. TC: O(NlogN) Sc: O(N)
	// 	- Sort both the arrays
	// 	- Two pointers while(a<n && b<m)
	// 	- if match add to ans or else if v1[a] < v2[b] a++; else b++;
    vector<int> common_element(vector<int>v1,vector<int>v2) {
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        int n = v1.size();
        int m = v2.size();

        int i=0;
        int j=0;

        vector<int> ans;
        while(i<n && j<m) {
        	if(v1[i] == v2[j]) {
        		ans.push_back(v1[i]);
        		v1[i] = INT_MIN;
        		i++;
        		j++;
        	} else if(v1[i] < v2[j]) {
        		i++;
        	} else {
        		j++;
        	}
        }

    	return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int>v1(n,0);
        for(int i=0;i<n;i++) {
            cin>>v1[i];
        }
        int m;
        cin>>m;
        vector<int>v2(m,0);
        for(int i=0;i<m;i++) {
            cin>>v2[i];
        }
        Solution ob;
        vector<int>result;
        result=ob.common_element(v1,v2);
        for(auto i:result) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}