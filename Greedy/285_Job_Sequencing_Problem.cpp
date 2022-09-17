/*
Job_Sequencing_Problem.cpp

Given a set of N jobs where each jobi has a deadline and profit 
associated with it.

Input : N = 4, Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output: 2 60

Input : N = 5 ,Jobs = {(1,2,100),(2,1,19),(3,2,27),(4,1,25),(5,1,15)}
Output: 2 127

https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/
*/

/*
struct Job 
{ 
    int id;  // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

bool comparator(Job a, Job b) {
    if(a.profit > b.profit) return true;    // no swap
    else return false;                      // swap
}

vector<int> JobScheduling(Job arr[], int n) { 
    sort(arr, arr+n, comparator);
    int maxi = arr[0].dead;

    for(int i=1; i<n; i++) {
        maxi = max(maxi, arr[i].dead);
    }

    int slot[maxi+1];
    for(int i=0; i<maxi+1; i++) slot[i] = -1;   // init -1

    int countJobs = 0, jobProfit = 0;
    
    for(int i=0; i<n; i++) {    // for each job
        for(int j=arr[i].dead; j>0; j--) {  // check if slot is there
            if(slot[j] == -1) {
                slot[j] = i;
                countJobs++;
                jobProfit+= arr[i].profit;
                break;
            }
        }
    }

    return {countJobs, jobProfit};
}