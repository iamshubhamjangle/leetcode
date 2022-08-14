/*
Target_Sum.cpp

You are given the array ‘ARR’ = [1, 1, 1, 1, 1], ‘TARGET’ = 3. The number of ways this target can be achieved is:
1. -1 + 1 + 1 + 1 + 1 = 3
2. +1 - 1 + 1 + 1 + 1 = 3
3. +1 + 1 - 1 + 1 + 1 = 3
4. +1 + 1 + 1 - 1 + 1 = 3
5. +1 + 1 + 1 + 1 - 1 = 3

Sample Input 1 :
2
5 3
1 1 1 1 1
4 3
1 2 3 1

Sample Output 2 :
5
2

https://www.codingninjas.com/codestudio/problems/target-sum_4127362
// Space Optimisation. TC: O(N*target) SC: O(target)
// Same code as 191_Partitions_With_Given_Difference.cpp
*/




// Space Optimisation. TC: O(N*target) SC: O(target)
int findWays(vector<int> &num, int sum) {
    int n = num.size();
    vector<int> prev(sum+1, 0), curr(sum+1, 0);

    if(num[0] == 0) prev[0] = 2;    // if(ind == 0) { if(sum == 0 && num[ind] == 0) return 2; }
    else prev[0] = 1;                // if(ind == 0) { sum == 0 || num[ind] == sum } return 1; }

    if(num[0] != 0 && num[0] <= sum) prev[num[0]] = 1;

    for(int ind=1; ind<n; ind++) {
        for(int j=0; j<=sum; j++) {
            int notake = prev[j];
            int take = 0;
            if(num[ind] <= j) take = prev[j - num[ind]];

            curr[j] = (take + notake);
        }
        prev = curr;
    }

    return prev[sum];
}
/**
* constrains 0 <= num[i] - numbers are positive integer only 
* Hence as per the formula we derived s2 = (totalSum - d) / 2
* 1. totalSum - d >= 0 (positive integers)
* 2. totalSum - d == EVEN (as the division show result in int only)
*/
int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    if(totalSum - d < 0 || (totalSum - d) % 2) return false;
    return findWays(arr, (totalSum - d) / 2);
}


int targetSum(int n, int target, vector<int>& arr) {
    return countPartitions(n, target, arr);
}
