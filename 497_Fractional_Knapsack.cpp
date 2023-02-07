/*
Fractional_Knapsack.cpp

https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
*/

class Solution {
    public:
    // We will fill the bag with max value/weight ratio items.
    // If we are not able to fit we can put fractional weight - W * (value/weight)
    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr+n, [](Item a, Item b){
            if((double)a.value / a.weight > (double)b.value / b.weight) return true;
            return false;
        });
        
        double maxValue = 0.0;
        for(int i=0; i<n; i++) {
            if(arr[i].weight <= W) {
                maxValue += arr[i].value;
                W -= arr[i].weight;
            } else {
                maxValue += W * ((double)arr[i].value / arr[i].weight);
                break;
            }
        }
        
        return maxValue;
    }
};