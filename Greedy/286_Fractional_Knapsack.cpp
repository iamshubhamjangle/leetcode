/*
Fractional_Knapsack.cpp

Given weights and values of N items, we need to put these items in a 
knapsack of capacity W to get the maximum total value in the knapsack.

Input: 	N = 3, W = 50
		values[] = {60,100,120}
		weight[] = {10,20,30}
Output: 240.00

https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
*/

// struct Item{
//     int value;
//     int weight;
// };


// TC: O(NlogN) SC: O(1)
bool comparator(Item a, Item b) {
	// true  -> noswap
	// false -> swap
	return ((double)a.value/(double)a.weight) > ((double)b.value/(double)b.weight);
}

class Solution {
    public:
    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr+n, comparator);	// sort based on Value/Weight

        double res = 0.0;				// max value in knapsack

        for(int i=0; i<n; i++) {
        	if(arr[i].weight <= W) {	// curr weight is less than req: take the whole
        		res += arr[i].value;
        		W -= arr[i].weight;
        	} else {					// else take only needed
        		res += W * ((double)arr[i].value / (double)arr[i].weight);
        		break;
        	}
        }

        return res;
    }
};