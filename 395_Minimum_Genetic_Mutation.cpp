/*
Minimum_Genetic_Mutation.cpp

https://leetcode.com/problems/minimum-genetic-mutation/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st{bank.begin(),bank.end()};
        if(!st.count(end)) return -1;
        
        //start BFS by pushing the starting mutation
        queue<string> Q;
        Q.push(start);
        int steps=0,s;
        string cur,t;
        while(!Q.empty()){
            s=Q.size();
            while(s--){
                cur=Q.front();
                Q.pop();
                if(cur==end) return steps;
                st.erase(cur);

                //as the length of mutation is 8 and it can take A,C,G,T
                //at each index we check the possibility of mutation by replcaing it with A,C,G,T
                for(int i=0;i<8;i++){
                    t=cur;
                    t[i]='A';
                    if(st.count(t)) Q.push(t);
                    t[i]='C';
                    if(st.count(t)) Q.push(t);
                    t[i]='G';
                    if(st.count(t)) Q.push(t);
                    t[i]='T';
                    if(st.count(t)) Q.push(t);
                }
            }
            steps++;
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<string> bank;

    bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};
    cout << s.minMutation("AACCGGTT","AAACGGTA", bank) << endl;
    return 0;
}