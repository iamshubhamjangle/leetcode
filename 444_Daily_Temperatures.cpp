/*
Daily_Temperatures.cpp

https://leetcode.com/problems/daily-temperatures/
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int>nge(n, 0); // initially all 0, stores distance between their next greater element and current temperature
        stack<int>st{};
        
        for(int i = n-1; i>=0; --i){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();
				
            if(!st.empty())
                nge[i] = st.top()-i; // distance between next greater and current
            
            st.push(i);
        }
        
        return nge;
    }
};