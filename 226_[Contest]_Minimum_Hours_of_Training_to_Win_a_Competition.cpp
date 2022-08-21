/*
[Contest]_Minimum_Hours_of_Training_to_Win_a_Competition.cpp

You are entering a competition, and are given two positive integers 
initialEnergy and initialExperience denoting your initial energy and 
initial experience respectively.

Input: initialEnergy = 5, initialExperience = 3, energy = [1,4,3,2], experience = [2,6,3,1]
Output: 8

Input: initialEnergy = 2, initialExperience = 4, energy = [1], experience = [3]
Output: 0

https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition/
*/

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n = energy.size();  // both sizes will be equal
        int res = 0;
        
        for(int i=0; i<n; i++) {
            // case 1: initial/curr energy <= new energy
            if(initialEnergy <= energy[i]) {
                res += energy[i] - initialEnergy + 1;
                initialEnergy += energy[i] - initialEnergy + 1;
            }
            
            // case 2: initial/curr exp <= new experience
            if(initialExperience <= experience[i]) {
                res += experience[i] - initialExperience + 1;
                initialExperience += experience[i] - initialExperience + 1;
            }
            
            // case 3: after each iteration
            initialExperience += experience[i]; // exp gets added up
            initialEnergy -= energy[i];         // energy gets reduced
        }
        
        return res;
    }
};

