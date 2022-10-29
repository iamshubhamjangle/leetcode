/*
[Contest]_Odd_String_Difference.cpp

Input: words = ["adc","wzy","abc"]
Output: "abc"

https://leetcode.com/contest/biweekly-contest-90/problems/odd-string-difference/
*/

class Solution {
public:
    string oddString(vector<string>& wordz) {
        int nz = wordz.size();
        int n = wordz[0].size();
        
        map<vector<int>,int> mpp;
        
        for(int i=0;i<nz;i++) {
            vector<int> temp;
            for(int j=1;j<n;j++) {
               temp.push_back(wordz[i][j]-wordz[i][j-1]);
            }
            mpp[temp]++;
        }
    
        vector<int> tempSaved;
    
        for(auto i : mpp)
            if(i.second==1)
                tempSaved=i.first;
    
        for(int i=0;i<nz;i++) {
            vector<int> temp;
            for(int j=1;j<n;j++) {
               temp.push_back(wordz[i][j]-wordz[i][j-1]);
            }
            if(temp==tempSaved)
                return(wordz[i]);
        }
        return(wordz[0]);
    }
};