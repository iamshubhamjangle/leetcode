/*
Shortest_Distance_to_Target_String_in_a_Circular_Array.cpp

https://leetcode.com/contest/weekly-contest-325/problems/shortest-distance-to-target-string-in-a-circular-array/
*/

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        unordered_map<string,vector<int>> ump;

        for(int i=0;i<words.size();++i) {
            ump[words[i]].push_back(i);
        }

        int mini = INT_MAX;
        if(ump.find(target) == ump.end())
        	return -1;
        else {
            for(int i=0; i<ump[target].size(); ++i){
                if(ump[target][i]>startIndex){
                    int a = ump[target][i]-startIndex;
                    int b = (int)words.size()-(ump[target][i]-startIndex);
                    mini = min({mini,a,b});
                } else {
                    int a = startIndex- ump[target][i];
                    int b = (int)words.size()-(startIndex- ump[target][i]);
                    mini = min({mini,a,b});
                }
            }
        }
        
        return mini;
    }
};