/*
Job_sequencing.cpp

https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

struct Job { 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution  {
    public:
    vector<int> JobScheduling(Job arr[], int n) {
        // sort by profit
        sort(arr, arr+n, [](Job a, Job b){
            if(a.profit > b.profit) return true; // noswap
            return false;   // swap
        });

        int maxDeadline = 0;
        for(int i=0; i<n; i++) maxDeadline = max(arr[i].dead, maxDeadline);

        vector<int> days(maxDeadline, -1);

        int jobs = 0, maxProfit = 0;
        for(int i=0; i<n; i++) {
            for(int j=arr[i].dead-1; j>=0; j--) {
                if(days[j] == -1) {
                    days[j] = arr[i].id;
                    jobs++;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }

        return {jobs, maxProfit};
    } 
};
