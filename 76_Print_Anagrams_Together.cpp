/*
Print_Anagrams_Together.cpp

Given an array of strings, return all groups of strings that are anagrams. 
The groups must be created in order of their appearance in the original array. 
Look at the sample case for clarification.

Note: The finial output will be in lexicographic order.

Input: N = 5, words[] = {act,god,cat,dog,tac}
Output:
act cat tac 
god dog

Input: N = 3, words[] = {no,on,is}
Output: 
no on
is

https://practice.geeksforgeeks.org/problems/print-anagrams-together/1#
	Method 1: sort & un-map. TC: O(N), SC: O(N)
		- sort each string keep it in un-map
		- value of map will be the unsorted string we get each time

*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        unordered_map<string, vector<string>> um;
        int n = string_list.size();

        for(int i=0; i<n; i++) {
        	string temp = string_list[i];
        	sort(temp.begin(), temp.end());
        	um[temp].push_back(string_list[i]);
        }

    	vector<vector<string>> ans;
        for(auto i: um) {
        	ans.push_back(i.second);
        }

        return ans;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}