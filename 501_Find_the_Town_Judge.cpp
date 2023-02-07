/*
Find_the_Town_Judge.cpp

https://leetcode.com/problems/find-the-town-judge/description/
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
		if(trust.empty() && n==1)
            return 1;
		
		vector<int> out(n+1,0); //outdegree means number of nodes that are trusted by given specific node 
		vector<int> in(n+1,0); //indegree means number of nodes that trusts a given specific node
		
		for(auto edge : trust){
            out[edge[0]]++;
            in[edge[1]]++;
        }
		
		for(int i=0;i<=n;i++){
            if(out[i]==0 && in[i]==n-1) // If current node doesn't trust anyone and all other trust me.
                return i;
        }
		
        return -1; //if there is no such node return -1
    }
};