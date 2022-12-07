/*
Divide_Players_Into_Teams_of_Equal_Skill.cpp

https://leetcode.com/contest/weekly-contest-322/problems/divide-players-into-teams-of-equal-skill/
*/


class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long res = 0;
        int n = skill.size();
    	
    	sort(skill.begin(), skill.end());
        
        for(int i=0; i<n/2; i++){
            if(skill[i] + skill[n-i-1] != skill[0] + skill[n-1]){
                return -1;
            }
            res += skill[i] * skill[n-i-1];
        }

        return res;
    }
};