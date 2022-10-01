/*
[Contest]_Remove_Letter_To_Equalize_Frequency.cpp

https://leetcode.com/contest/biweekly-contest-88/problems/remove-letter-to-equalize-frequency/
*/

class Solution {
public:
    bool check(map<char,int> mymap){
        set<int>st;
        for(auto it:mymap){
            if(it.second>0)
                st.insert(it.second);
        }
        if(st.size()==1)return true;
        return false;
    }
    
    bool equalFrequency(string word) {
        map<char,int> mymap;
        set<int> st;
        for(auto it: word) mymap[it]++;
        for(auto it: mymap){
            mymap[it.first]--;
            if(check(mymap)) return true;
            mymap[it.first]++;
        }
        return false;
    }
};