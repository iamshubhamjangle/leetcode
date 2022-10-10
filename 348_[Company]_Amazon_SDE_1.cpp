/*
[Company]_Amazon_SDE_1.cpp
*/

#include <bits/stdc++.h>
using namespace std;

int minimizeMemory(vector<int> processes, int m) {
    int n = processes.size();
    if(n == 1 && m > 0) return 0;
    if(n == 1 && m == 0) return processes[0];

    int i=0;
    int j=0;
    int curr_sum = 0;
    int maxi = INT_MIN;

    while(j < n) {
        curr_sum += processes[j];
        if(j-i+1 < m) {
            j++;
        } else if(j-i+1 == m) {
            maxi = max(curr_sum, maxi);
            curr_sum = curr_sum - processes[i++];
            j++;
        }
    }

    int total = accumulate(processes.begin(), processes.end(), 0);
    return total - maxi;
}

int main(){
    vector<int> processes;

    processes = {10, 4, 8, 1};  // max sum = 12, 23-12 = 9
    cout << minimizeMemory(processes, 2) << endl;

    processes = {10};  // 10
    cout << minimizeMemory(processes, 0) << endl;

    processes = {10};  // 0
    cout << minimizeMemory(processes, 1) << endl;
}